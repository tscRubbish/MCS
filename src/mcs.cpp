#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "mcs_def.h"
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <regex>

int cur_constant=0;
int cur_assign=0;

int cur_model=0;
int cur_val=0;
int cur_def=0;
int _i,_j,len;
int para_size=0;
char* fname;
//PARAIDXLIST pil;
int para_idx_tmp[MAX_N_PARA];
int mp[MAX_N_DEF];

int getNameLength(char *s){
    int len=1;
    while ((*(s+len*sizeof(char))>='a'&&*(s+len*sizeof(char))<='z')||(*(s+len*sizeof(char))>='A'&&*(s+len*sizeof(char))<='Z')
        ||(*(s+len*sizeof(char))>='0'&&*(s+len*sizeof(char))<='9')){
        len++;
        if (*(s+len*sizeof(char))=='\n'||*(s+len*sizeof(char))==' ') return len;
    }
    return len;
}

int getDefByName(std::string s){
    //printf("def size = %d\n",Def_Table.size());
    for (_i=0;_i<Def_Table.size();_i++){
            if (!s.compare( Def_Table[_i]->fun_name)){
                    return _i;
                    break;
            }
    }
    return -1;
}

void printAssign(){
    printf("\ncur_def = %d\n",cur_def);
    for (_i=0;_i<cur_def;_i++){
        printf("def id =%d : %s\n",_i,Def_Table[_i]->fun_name);
    }
    printf("\nModel id = %d\n Assign id = %d\n",cur_model,cur_assign);
    printf("para size = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
    printf("def id = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx);
    printf("%s(",Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->fun_name);
    for (_i=0;_i<Model_Table[cur_model]->Assign_Table[cur_assign]->para_size;_i++){
        printf("%d,",Model_Table[cur_model]->Assign_Table[cur_assign]->para_list[_i]);
    }
    printf(") = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->res);
 }

void printModel(){
    // for (_i=0;_i<cur_constant;_i++){
    //     printf("Model id : %d , constant %s \n", cur_model, Model_Table[cur_model]->Constant_Table[_i]->const_name);
    // }
    for (_i=0;_i<cur_assign;_i++){
        printf("Assign is %s (", Def_Table[Model_Table[cur_model]->Assign_Table[_i]->fun_idx]->fun_name);
        for (_j=0;_j<Model_Table[cur_model]->Assign_Table[_i]->para_size;_j++){
            printf("%d ,",Model_Table[cur_model]->Assign_Table[_i]->para_list[_j]);
        }
        printf(" )= %d \n", Model_Table[cur_model]->Assign_Table[_i]->res);
    }
}
void printTerm(TERM term){
    FILE* fp;
    fp = fopen("result.txt","a");
    if (term->isfun==0){
        fprintf(fp,"$%c", 'a'+term->idx);
        fclose(fp);
        return;
    }
    fprintf(fp,"%s(", Def_Table[term->idx]->fun_name);
    fclose(fp);
    for (int i=0;i<term->para_size;i++){
        fp = fopen("result.txt","a");
        if (i>=1) fprintf(fp,",");
        fclose(fp);
        printTerm(term->para_list[i]);
    }
    fp = fopen("result.txt","a");
    fprintf(fp,")");
    fclose(fp);
}
int hasRewrite(TERM term1 ,TERM term2){
    if (term1->isfun!=term2->isfun) return 0;
    if (term1->isfun==0) {
        if (mp[term1->idx]>=0&&mp[term1->idx]!=term2->idx) return 0;
        mp[term1->idx]=term2->idx;
        return 1;
    }
    if (term1->idx!=term2->idx) return 0;
    for (int i=0;i<term1->para_size;i++){
        if (!hasRewrite(term1->para_list[i],term2->para_list[i])) return 0;
    }
    return 1;
}

int calculateByModel(TERM term,int *para_val_list,int model_id){
    for (int i=0;i<Model_Table[model_id]->assign_size;i++){
        if (Model_Table[model_id]->Assign_Table[i]->fun_idx==term->idx){
            int flag=1;
            for (int j=0;j<term->para_size;j++){
                if (Model_Table[model_id]->Assign_Table[i]->para_list[j]!=para_val_list[j]){
                    flag=0;
                    break;
                }
            }
            if (flag) return Model_Table[model_id]->Assign_Table[i]->res;
        }
    }
    return -1;
}
int getResult(TERM term,int* val_list,int model_id){
    if (term->isfun==0){
        return val_list[term->idx];
    }
    int *para_val_list;
    para_val_list=(int*)malloc(sizeof(int)*term->para_size);
    for (int i=0;i<term->para_size;i++){
        para_val_list[i]=getResult(term->para_list[i],val_list,model_id);
        if (para_val_list[i]==-1) 
            return -1;
    }
    int res=calculateByModel(term,para_val_list,model_id);
    free(para_val_list);
    return res;
}
int enumerateVal(int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
    if (pren_id == val_size){
        int res1=getResult(term1,val_list,model_id);
        int res2=getResult(term2,val_list,model_id);
        if (res1==-1||res2==-1) 
            return 0;
        return res1==res2;
    }
    for (int i=0;i<Model_Table[model_id]->model_size;i++){
        val_list[pren_id]=i;
        int res=enumerateVal(pren_id+1,val_list,term1,term2,model_id);
        if (res==0) 
            return 0;
    }
    return 1;
}
int checkByModel(TERM term1,TERM term2){
    int *val_list;
    val_list=(int*)malloc(sizeof(int)*val_size);
    int res=0;
    for (int i=0;i<cur_model;i++){
        //printf("model_id = %d\n",i);
        res += enumerateVal(0,val_list,term1,term2,i);
    }
    if (res==cur_model) {
        FILE* fp;
        fp = fopen("result.txt","a");
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]==1)
        //         fprintf(fp,"/forall %s ", Val_Table[i]->val_name);
        //     else if (pren_list[i]==0) fprintf(fp,"/exist %s ", Val_Table[i]->val_name);
        // }
        fclose(fp);
        printTerm(term1);
        fp = fopen("result.txt","a");
        fprintf(fp," = ");
        fclose(fp);
        printTerm(term2);
        fp = fopen("result.txt","a");
        fprintf(fp,"\n");
        fclose(fp);
        //AddFormula(pren_list,term1,term2);
        //printf("formula is right\n");
        return 1;
    }
    //printf("formula is false\n");
    free(val_list);
    return 0;
}
void getLitInTerm(TERM term,int* hasLit){
    if (term->isfun==0){
        hasLit[term->idx]=1;
        return;
    }
    for (int i=0;i<term->para_size;i++){
        getLitInTerm(term->para_list[i],hasLit);
    }
}
void generateFormula(){
    for (int i1=1;i1<=max_depth;i1++){
        for (int j1=0;j1<term_num[i1];j1++){
            for (int i2=0;i2<=i1;i2++){
                for (int j2=0;j2<term_num[i2];j2++){
                    if (i2==i1&&j2==j1) break;
                    int flag = checkByModel(Term_Table[i1][j1],Term_Table[i2][j2]);
                    if (flag){
                        FORMULA f=(FORMULA)malloc(sizeof(struct Formula));
                        f->term1 = Term_Table[i1][j1];
                        f->term2 = Term_Table[i2][j2];
                        Formula_List.push_back(f);
                    }
                }
            }
        }
    }
}
void allocatePara(int depth,int nowdepth,int para_idx,int para_num,TERM term){
    //printf("allocate nowdep=%d para_idx=%d \n",nowdepth,para_idx);
    if (para_idx>=para_num){
        if (nowdepth>0) return;
        TERM t=(TERM)malloc(sizeof(struct Term));
        t->isfun=term->isfun;
        t->depth=term->depth;
        t->para_size=term->para_size;
        t->idx=term->idx;
        t->para_list = (TERM*)malloc(sizeof(TERM)*term->para_size);
        for (int i=0;i<term->para_size;i++){
            t->para_list[i]=term->para_list[i];
        }
        for (int j=0;j<term_num[depth];j++){
            memset(mp,-1,sizeof(mp));
            if (depth>=2&&hasRewrite(t,Term_Table[depth][j])) return;
        }

        Term_Table[depth].push_back(t);
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        for (int k=0;k<term_num[i];k++){
            term->para_list[para_idx]=Term_Table[i][k];
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
        }
    }
}
void generateTerm(){
    //Term_Table = malloc(sizeof(std::vector<TERM> )*max_depth);
    Term_Table = new std::vector<TERM> [max_depth];
    term_num = (int*)malloc(sizeof(int)*max_depth);
    for (int i=0;i<=max_depth;i++){
        printf("i=%d\n",i);
        if (i==0){
            for (int j=0;j<val_size;j++){
                printf("j=%d\n",j);
                TERM term=(TERM)malloc(sizeof(struct Term));
                term->isfun=0;
                term->depth=0;
                term->para_size=0;
                term->idx=j;
                Term_Table[i].push_back(term);
                term_num[i]++;
            }
            for (int j=0;j<cur_def;j++){
                if (Def_Table[j]->para_size==0){
                    printf("Constant : id = %d , cname = %s\n",j,Def_Table[j]->fun_name);
                    TERM term=(TERM)malloc(sizeof(struct Term));
                    term->isfun=1;
                    term->depth=0;
                    term->para_size=0;
                    term->idx=j;
                    Term_Table[i].push_back(term);
                }
            }
        }else {
            for (int j=0;j<cur_def;j++){
                if (Def_Table[j]->para_size>0){
                    TERM term=(TERM)malloc(sizeof(struct Term));
                    term->isfun=1;
                    term->depth=i;
                    term->para_size=Def_Table[j]->para_size;
                    term->idx=j;
                    term->para_list=(TERM*)malloc(sizeof(TERM)*term->para_size);
                    allocatePara(i,i-1,0,term->para_size,term);
                }
            }
        }
    }
    FILE* fp;
    fp = fopen("result.txt","a");
    for (int i=0;i<=max_depth;i++){
        for (int k=0;k<term_num[i];k++){
            printTerm(Term_Table[i][k]);
             fp = fopen("result.txt","a");
             fprintf(fp,"\n");
             fclose(fp);
        }
    }
    fp = fopen("result.txt","a");
    fprintf(fp,"\n");
    fclose(fp);
}
int max(int a,int b){
    return (a>b)?a:b;
}
int main(int argc, char **argv) {
 int option;
    while ((option = getopt(argc, argv, "d:f:o:p")) != -1) {
        switch (option) {
            case 'd':
                max_depth = atoi(optarg);
                std::cout << "maxDepth: " << optarg << std::endl;
                break;
            case 'f':
                std::cout << "Filename: " << optarg << std::endl;
                inputFile = optarg;
                break;
            case 'o':
                std::cout << "outputFile: " << optarg << std::endl;
                outFile = optarg;
                break;
            case 'p':
                std::cout << "needProve: "  << std::endl;
                needProve = true;
                break;
            default:
                std::cerr << "Unknown option" << std::endl;
                return 1;
        }
    }
    FILE* fp = fopen("result.txt","w");
    fprintf(fp,"");
    fclose(fp);
    readModelFromFile(inputFile);
    generateTerm(); 
    generateFormula();