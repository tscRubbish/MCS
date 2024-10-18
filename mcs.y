%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "mcs_def.h"
#include <vector>

int yylex(void);
void yyerror(char *); 
extern int yylineno;

//int maxModelSize=1024
//model modelList[1024];
//int model_size=0;
//def* now_def_list;
//formula* now_formula_list;
int cur_constant=0;
int cur_assign=0;

int cur_model=0;
int cur_val=0;
int cur_def=0;
int _i,_j,len;
int para_size=0;
char* fname;
int para_idx_tmp[MAX_N_PARA];
int mp[MAX_N_DEF];

bool createDef;

void initNewModel();
int getDefByName(char *s);
int getNameLength(char *s);
void printModel();
void printAssign();
void generateTerm();
void generateFormula();


%}

%union {
    int Intval;           
    char* str;           
};

%token LP
%token RP
%token EQ
%token Split
%token Annotate
%token END
%token STR
%token SP_STR
%token INT

%type<str> SP_STR
%type<str> INT
%type<str> STR 

%start MCS

%%
MCS: Model_List {
    generateTerm(); 
    generateFormula();
};

Model_List: Model_List Model
    {
        printModel();
        initNewModel();
    }
    | Model
    {
        printModel();
        initNewModel();
    };

Model:
    {
        MODEL model=(MODEL)malloc(sizeof(struct Model));
        
        Model_Table.push_back(model);
    }
    Annotate STR EQ INT
    Annotate STR EQ INT
    Annotate STR STR STR INT
    {
        Model_Table[cur_model]->model_size=atoi($14);
    }
    Res_List;

Res_List: Res_List Res
    | Res;

Res : SP_STR 
    {
        len = strlen( $1 );
        //fname = (char*) malloc(sizeof(char)*(len+1));
        //strcpy(fname , $1);
        //printf("Len = %d\n",strlen($1));
        createDef=false;
        int idx=getDefByName($1);
        //printf("%s\n",fname);
        //printf("%d\n",idx);

        if (idx==-1) {
            createDef=true;
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , $1);
            printf("def name = %s\n",def->fun_name);
            Def_Table.push_back(def);
        }
        //printf("%d\n",cur_assign);

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = createDef?cur_def:idx;

        para_size = 0;

    }LP Para_List RP EQ INT END
    {
        if (createDef){
            Def_Table[cur_def]->para_size=para_size;
            //printf("Def id = %d ,Def name = %s\n",cur_def,Def_Table[cur_def]->fun_name);
            cur_def++;
        }
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->para_size;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi($7);
        printAssign();
        cur_assign++;
    }
    | STR 
    {
        len = strlen( $1 );
        createDef=false;
        int idx=getDefByName($1);
        //printf("%s\n",fname);
        //printf("%d\n",idx);

        if (idx==-1) {
            createDef=true;
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , $1);
            printf("def name = %s\n",def->fun_name);
            Def_Table.push_back(def);
        }
        //printf("%d\n",cur_assign);

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = createDef?cur_def:idx;

        para_size = 0;

    }LP Para_List RP EQ INT END
    {
        if (createDef){
            Def_Table[cur_def]->para_size=para_size;
            cur_def++;
        }
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx]->para_size;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi($7);
        printAssign();
        cur_assign++;
    }
    | STR EQ INT END
    {
        len =  strlen( $1 );
        //fname = (char*) malloc(sizeof(char)*(len+1));
        //strcpy(fname , $1);

        int idx=getDefByName($1);

        if (idx==-1){
            DEF def=(DEF)malloc(sizeof(struct Def));
            def->fun_name=(char*) malloc(sizeof(char)*(len));
            strcpy(def->fun_name , $1);
            def->para_size=0;
            Def_Table.push_back(def);
            cur_def++;
        }

        INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = idx==-1?cur_def:idx;
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = 0;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = atoi($3);
        printAssign();
        cur_assign++;
    };

Para_List : Para_List Split INT
    {
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_list.push_back(atoi($3));
        para_size++;
    }
    | INT
    {
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_list.push_back(atoi($1));
        para_size++;
    };

%%
void initNewModel(){
    cur_assign=0;
    
    cur_model+=1;
}

int getDefByName(char *s){
    //printf("def size = %d\n",Def_Table.size());
    for (_i=0;_i<Def_Table.size();_i++){
            if (!strcmp(s, Def_Table[_i]->fun_name)){
                    return _i;
                    break;
            }
    }
    return -1;
}
int getNameLength(char *s){
    int len=1;
    // while ((*(s+len*sizeof(char))>='a'&&*(s+len*sizeof(char))<='z')||(*(s+len*sizeof(char))>='A'&&*(s+len*sizeof(char))<='Z')
    //     ||(*(s+len*sizeof(char))>='0'&&*(s+len*sizeof(char))<='9')){
    while (!(*(s+len*sizeof(char))==' '||*(s+len*sizeof(char))=='\t'||*(s+len*sizeof(char))=='\n')){
        len++;
        if (*(s+len*sizeof(char))=='\n'||*(s+len*sizeof(char))==' ') return len;
    }
    return len;
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
        fprintf(fp,"$%s", 'a'+term->idx);
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
//int enumerateVal(int *pren_list,int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
int enumerateVal(int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
    if (pren_id == val_size){
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]!=-1)
        //         printf("%s = %s,",Val_Table[i]->val_name,Model_Table[model_id]->Constant_Table[val_list[i]]->const_name);
        // }
        //printf("\n");
        int res1=getResult(term1,val_list,model_id);
        int res2=getResult(term2,val_list,model_id);
        // printf("res1 = %d\n",res1);
        // printf("res2 = %d\n",res2);
        if (res1==-1||res2==-1) 
            return 0;
        return res1==res2;
    }
    // if (pren_list[pren_id]==-1) 
    //     return enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
    //int t=0;
    for (int i=0;i<Model_Table[model_id]->model_size;i++){
        val_list[pren_id]=i;
        int res=enumerateVal(pren_id+1,val_list,term1,term2,model_id);
        //if (res!=-1)
         //   t+=res;
        if (res==0) 
            return 0;
        // if (pren_list[pren_id]==1){
        //     if (res==0) 
        //         return 0;       
        // }else {
        //     if (res==1)
        //         return 1;
        // }
    }
    //if (t==0) return -1;
    return 1;
}

//int checkByModel(int *pren_list,TERM term1,TERM term2){
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
        //}
        // fclose(fp);
        // printTerm(term1);
        // fp = fopen("result.txt","a");
        // fprintf(fp," = ");
        // fclose(fp);
        // printTerm(term2);
        // fp = fopen("result.txt","a");
        // fprintf(fp,"\n");
        // fclose(fp);
        //printf("formula is right\n");
        return 1;
    }
    //printf("formula is false\n");
    free(val_list);
    return 0;
}
// void getLitInTerm(TERM term,int* hasLit){
//     if (term->isfun==0){
//         hasLit[term->idx]=1;
//         return;
//     }
//     for (int i=0;i<term->para_size;i++){
//         getLitInTerm(term->para_list[i],hasLit);
//     }
// }
// //pren=1表示任意，=0表示存在量词
// int generatePREN(int id,int* pren_list,TERM term1,TERM term2,int* hasLit){
//     if (id>val_size){
//         int forall_sum=0;
//         for (int i=0;i<val_size;i++)
//             if (pren_list[i]==1) forall_sum+=1;
//         // for (int i=0;i<val_size;i++){
//         //     if (pren_list[i]==1)
//         //         printf("/forall %s ", Val_Table[i]->val_name);
//         //     else if (pren_list[i]==0) printf("/exist %s ", Val_Table[i]->val_name);
//         // }
//         // printTerm(term1);
//         // printf(" = ");
//         // printTerm(term2);
//         // printf("\n");
//         if (forall_sum>0)
//             return checkByModel(pren_list,term1,term2);
//         else return 0;
//     }
//     if (!hasLit[id]) {
//         pren_list[id]=-1;
//         return generatePREN(id+1,pren_list,term1,term2,hasLit); 
//     }
//     int flag;
//     for (int i=1;i>=0;i--){
//         if (i==0&&gen_exist==0) continue;  
//         pren_list[id]=i;
//         flag=generatePREN(id+1,pren_list,term1,term2,hasLit);
//         if (flag&&i==1) return 0;
//     }
//     return flag;
// }
//todo: 之后要将Formula建模成数据类型
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

    // int *hasLit=(int*)malloc(sizeof(int)*val_size);
    // int* pren_list=(int*)malloc(sizeof(int)*val_size);


    // for (int i1=1;i1<=max_depth;i1++){
    //     TERMLIST termlist1 = Term_Table[i1];
    //     for (int j1=0;j1<term_num[i1];j1++){
    //         memset(hasLit,0,sizeof(hasLit));
    //         TERM t1=termlist1->cur;
    //         for (int i2=0;i2<=i1;i2++){
    //             TERMLIST termlist2 = Term_Table[i2];
    //             for (int j2=0;j2<term_num[i2];j2++){
    //                 if (i2==i1&&j2==j1) break;
    //                 TERM t2=termlist2->cur;
    //                 for (_i=0;_i<val_size;_i++)
    //                     hasLit[_i]=0;
    //                 getLitInTerm(t1,hasLit);
    //                 getLitInTerm(t2,hasLit);
    //                 generatePREN(0,pren_list,t1,t2,hasLit);
    //                 termlist2=termlist2->next;
    //             }
    //         }
    //         termlist1=termlist1->next;
    //     }
    // }
    // free(hasLit);
    // free(pren_list);
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
        // if (term_num[depth]==0){
        //     Term_Table[depth]=(TERMLIST)malloc(sizeof(struct TermList));
        //     Term_Table[depth]->cur=t;
        //     Term_Table[depth]->next=NULL;
        // }else {
        //     TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
        //     termlist->cur=t;
        //     termlist->next=NULL;
        //     TERMLIST cur=Term_Table[depth];
        //     memset(mp,-1,sizeof(mp));
        //     if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
        //     while (cur->next!=NULL){
        //         cur=cur->next;
        //         memset(mp,-1,sizeof(mp));
        //         if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
        //     }
        //     cur->next=termlist;
        //     // termlist->next = Term_Table[depth];
        //     // termlist->cur = term;
        //     // Term_Table[depth] = termlist;
        // }

        Term_Table[depth].push_back(t);
        // printf("get term : ");
        // printTerm(Term_Table[depth]->cur);
        // printf("\n");
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        //TERMLIST termlist = Term_Table[i];
        for (int k=0;k<term_num[i];k++){
            //term->para_list[para_idx] = termlist->cur;
            term->para_list[para_idx]=Term_Table[i][k];
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
            //termlist = termlist->next;
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
                // if (term_num[i]==0){
                //     Term_Table[i]=(TERMLIST)malloc(sizeof(struct TermList));
                //    Term_Table[i]->cur=term;
                // }else {
                //     TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
                //     termlist->cur=term;
                //     termlist->next=NULL;
                //     TERMLIST cur=Term_Table[i];
                //     while (cur->next!=NULL){
                //        cur=cur->next;
                //     }
                //     cur->next=termlist;
                //         //  termlist->next = Term_Table[i];
                //         //  termlist->cur = term;
                //         //  Term_Table[i] = termlist;
                // }

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
        // TERMLIST termlist = Term_Table[i];
        // fp = fopen("result.txt","a");
        // fprintf(fp,"dep = %d  ,  term_num has %d\n",i,term_num[i]);
        // fclose(fp);
        // for (int k=0;k<term_num[i];k++){
        //     printTerm(termlist->cur);
        //     fp = fopen("result.txt","a");
        //     fprintf(fp,"\n");
        //     fclose(fp);
        //     termlist = termlist->next;
        // }
    }
    fp = fopen("result.txt","a");
    fprintf(fp,"\n");
    fclose(fp);
}
int max(int a,int b){
    return (a>b)?a:b;
}
void yyerror(char *s) {
    //fprintf(stdout, "%s\n", s);
    //STR LFun para_list RFun EQ STR LFun para_list RFun {printf("left fun is %s , right fun is %s\n",$1,$6);}|
    extern int yylineno;	// defined and maintained in lex
	extern char *yytext;	// defined and maintained in lex
	int len=strlen(yytext);
	int i;
	char buf[512]={0};
	for (i=0;i<len;++i)
	{
		sprintf(buf,"%s%d ",buf,(char)yytext[i]);
	}
    fprintf(stderr, "ERROR: %s at symbol '%s' on line %d\n", s, buf, yylineno);
	yyparse();
}
int main(int argc, char **argv) {
    FILE* fp = fopen("result.txt","w");
    fprintf(fp,"");
    fclose(fp);
    yyparse();
}
