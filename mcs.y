%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "mcs_def.h"
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
//PARAIDXLIST pil;
int para_idx_tmp[MAX_N_PARA];
int mp[MAX_N_DEF];

//int* constant_id;
//int* id_constant;

%}

%union {
    int Intval;           
    char* str;           
};

%token ModelSize
%token TermDepth
%token ValSize
%token DefSize
%token ConstantSize
%token AssignSize

%token ModelSplit
%token LFun
%token RFun
%token EQ
%token STR
%token INT_NUMBER
%token Split
%token DefSplit
%token End
%token ResSplit

%type<str> INT_NUMBER
%type<str> STR 

%start MCS

%%
MCS: ModelSize INT_NUMBER
    {
        model_size = atoi($2);
        Model_Table = (MODEL*)malloc(sizeof(MODEL)*model_size);
    }
    Split TermDepth INT_NUMBER
    {
        max_depth= atoi($6);
        Term_Table = (TERMLIST*)malloc(sizeof(TERMLIST)*max_depth);
        term_num = (int*)malloc(sizeof(int)*max_depth);
    }
    Split ValSize INT_NUMBER
    {
        val_size=atoi($10);
        Val_Table = (VAL*)malloc(sizeof(VAL)*val_size);
        printf("Val number = %d\n",atoi($10));
    } 
    Split DefSize INT_NUMBER
    {
        def_size=atoi($14);
        Def_Table = (DEF*)malloc(sizeof(DEF)*def_size);
        printf("Def number = %d\n",atoi($14));
    } 
    ResSplit val_list ResSplit def_list ResSplit model_list
    {
        generateTerm(); 
        generateFormula();
    };

val_list: val_list Split STR
    {
        len = getNameLength( $3 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $3);

        Val_Table[cur_val]=(VAL)malloc(sizeof(struct Val));
        Val_Table[cur_val++]->val_name =fname;
        printf("val name : %s , name len is %d\n", fname, len);
    }
    | STR
    {
        len = getNameLength( $1 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $1);

        Val_Table[cur_val]=(VAL)malloc(sizeof(struct Val));
        Val_Table[cur_val++]->val_name =fname;
        printf("val name : %s , name len is %d\n", fname, len);
    };

def_list: def_list Split def 
    |   def ;

def :   {
            Def_Table[cur_def] = (DEF)malloc(sizeof(struct Def));
            Def_Table[cur_def]->para_size=0;
        }
        STR 
        {
            len = getNameLength( $2 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $2);

            Def_Table[cur_def]->fun_name =fname;
            printf("fun def : %s  len is %d\n", fname, len);
        }
        LFun INT_NUMBER RFun 
        {
            Def_Table[cur_def]->para_size = atoi($5);
            cur_def++;
            printf("def para size is %d \n", atoi($5));
            //printf("len = %d\n", len);
        };

model_list:  End 
    |   ModelSplit 
        {
            Model_Table[cur_model]=(MODEL)malloc(sizeof(struct Model));
            printf("model id = %d\n",cur_model);
        }
        model 
        {
            //max_constant_num = max(max_constant_num,cur_constant);
            printModel();
            initNewModel();
        } 
        model_list ;

model: ConstantSize INT_NUMBER
        {
           Model_Table[cur_model]->constant_size=atoi($2);
           Model_Table[cur_model]->Constant_Table=(CONSTANT*)malloc(sizeof(CONSTANT)*Model_Table[cur_model]->constant_size);
           printf("Constant number = %d\n",atoi($2));
        } 
        ResSplit constant_list ResSplit AssignSize INT_NUMBER 
        {
            Model_Table[cur_model]->assign_size =atoi($8);
            Model_Table[cur_model]->Assign_Table = (INPUTASSIGN*)malloc(sizeof(INPUTASSIGN)*Model_Table[cur_model]->assign_size);
            printf("Assign number = %d\n",atoi($8));
        }    
        ResSplit res_list ;

constant_list: constant_list Split STR
    {
        len = getNameLength( $3 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $3);
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }|
    constant_list Split INT_NUMBER
    {
        len = getNameLength( $3 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $3);
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
    | STR
    {
        len = getNameLength( $1 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $1);
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    }
    |INT_NUMBER
    {
        len = getNameLength( $1 );
        fname = (char*) malloc(sizeof(char)*(len+1));
        strcpy(fname , $1);
        Model_Table[cur_model]->Constant_Table[cur_constant]=(CONSTANT)malloc(sizeof(struct Constant));
        Model_Table[cur_model]->Constant_Table[cur_constant++]->const_name = fname;
        printf("constant name : %s , name len is %d\n", fname, len);
    };

res_list: {
            Model_Table[cur_model]->Assign_Table[cur_assign]=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
            Model_Table[cur_model]->Assign_Table[cur_assign]->para_size=0;
        }
        res ResSplit res_list
        |    
        ;

res:    fun EQ STR 
        {
            printf("eq res is %s\n",$3);
            len = getNameLength( $3 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $3);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->res_idx=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no definition of constant %s" ,$3);
                exit(1);
            }
            cur_assign++;
            free(fname);
        }|
        fun EQ INT_NUMBER
        {
            printf("eq res is %s\n",$3);
            len = getNameLength( $3 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $3);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->res_idx=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no definition of constant %s" ,$3);
                exit(1);
            }
            cur_assign++;
            free(fname);
        };

// para_list: fun
//     | para_list Split fun
//     | STR {printf("para has %s\n",$1);};
//     | para_list Split STR{printf("para has %s\n",$3);}
    
fun: STR
        {
            printf("fun STR = %s\n",$1);
            len = getNameLength( $1 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $1);

            for (_i=0;_i<def_size;_i++){
                if (!strcmp(fname,Def_Table[_i]->fun_name)){
                    Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx=_i;
                    break;
                }
            }
            if (_i==def_size){
                printf("error : no exist definition of function %s" ,$1);
                exit(1);
            }
            free(fname);
        }
        LFun para_list RFun 
        {
            printf("assign para size = %d\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
            Model_Table[cur_model]->Assign_Table[cur_assign]->para_list_idx = (int*) malloc(sizeof(int)* Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
            for (_i=0;_i<Model_Table[cur_model]->Assign_Table[cur_assign]->para_size;_i++){
                 Model_Table[cur_model]->Assign_Table[cur_assign]->para_list_idx[_i] = para_idx_tmp[_i];
            }
        };

para_list:  para_list Split STR 
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            //pil->next=(PARAIDXLIST)malloc(sizeof(struct ParaIdxList));

            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,$3);
            len = getNameLength( $3 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $3);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of constant %s" ,fname);
                exit(1);
            }
            free(fname);
        }
        |para_list Split INT_NUMBER
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            //pil->next=(PARAIDXLIST)malloc(sizeof(struct ParaIdxList));

            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,$3);
            len = getNameLength( $3 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $3);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of constant %s" ,fname);
                exit(1);
            }
            free(fname);
        }
        | STR 
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,$1);

            len = getNameLength( $1 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $1);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of function %s" ,fname);
                exit(1);
            }
            free(fname);
        }
        |INT_NUMBER
        {
            ( Model_Table[cur_model]->Assign_Table[cur_assign]->para_size)+=1;
            printf("%d'th : para STR = %s\n", Model_Table[cur_model]->Assign_Table[cur_assign]->para_size,$1);

            len = getNameLength( $1 );
            fname = (char*) malloc(sizeof(char)*(len+1));
            strcpy(fname , $1);

            for (_i=0;_i<Model_Table[cur_model]->constant_size;_i++){
                if (!strcmp(fname, Model_Table[cur_model]->Constant_Table[_i]->const_name)){
                    para_idx_tmp[ Model_Table[cur_model]->Assign_Table[cur_assign]->para_size-1]=_i;
                    break;
                }
            }
            if (_i==Model_Table[cur_model]->constant_size){
                printf("error : no exist definition of function %s" ,fname);
                exit(1);
            }
            free(fname);
        };

%%
void initNewModel(){
    //for (_i=0;_i<cur_def;_i++){
        //free(Def_Table[_i]->fun_name);
        //free(Def_Table[_i]);
    //}
    //for (_i;_i<cur_assign;_i++){
        //free(Assgin_Table[_i]->para_list_idx);
        //free(Assgin_Table[_i]);
    //}
    cur_assign=0;
    cur_constant=0;
    
    cur_model+=1;
    //memset(term_num,0,sizeof(term_num));
    //pil=NULL;

    // model now=model_list[model_size];
    // now.max_def_size=1024;
    // now.def_size=0;
    // now.max_formula_size=1024;
    // now.formula_size=0;
    // now.def_list=(def*)malloc(sizeof(def)*now.max_def_size);
    // now.formula_list=(formula*)malloc(sizeof(formula)*now.max_formula_size);
}
// void createNewDef(char* s,int n){
//     model now=model_list[model_size];
//     def* Def=&now.def_list[now.def_size++];
//     Def->para_num=n;
//     Def->name=s;
//     Def->name_size=getNameLength(s);
// }
int getNameLength(char *s){
    int len=1;
    while ((*(s+len*sizeof(char))>='a'&&*(s+len*sizeof(char))<='z')||(*(s+len*sizeof(char))>='A'&&*(s+len*sizeof(char))<='Z')
        ||(*(s+len*sizeof(char))>='0'&&*(s+len*sizeof(char))<='9')){
        len++;
        if (*(s+len*sizeof(char))=='\n'||*(s+len*sizeof(char))==' ') return len;
    }
    return len;
}

void printModel(){
    for (_i=0;_i<cur_constant;_i++){
        printf("Model id : %d , constant %s \n", cur_model, Model_Table[cur_model]->Constant_Table[_i]->const_name);
    }
    for (_i=0;_i<cur_assign;_i++){
        printf("Assign is %s (", Def_Table[Model_Table[cur_model]->Assign_Table[_i]->fun_idx]->fun_name);
        for (_j=0;_j<Model_Table[cur_model]->Assign_Table[_i]->para_size;_j++){
            printf("%s ,",Model_Table[cur_model]->Constant_Table[Model_Table[cur_model]->Assign_Table[_i]->para_list_idx[_j]]->const_name);
        }
        printf(" )= %s \n", Model_Table[cur_model]->Constant_Table[Model_Table[cur_model]->Assign_Table[_i]->res_idx]->const_name);
    }
}
void printTerm(TERM term){
    FILE* fp;
    fp = fopen("result.txt","a");
    if (term->isfun==0){
        fprintf(fp,"%s", Val_Table[term->idx]->val_name);
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
                if (Model_Table[model_id]->Assign_Table[i]->para_list_idx[j]!=para_val_list[j]){
                    flag=0;
                    break;
                }
            }
            if (flag) return Model_Table[model_id]->Assign_Table[i]->res_idx;
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
int enumerateVal(int *pren_list,int pren_id,int *val_list,TERM term1,TERM term2,int model_id){
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
            return -1;
        return res1==res2;
    }
    if (pren_list[pren_id]==-1) 
        return enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
    int t=0;
    for (int i=0;i<Model_Table[model_id]->constant_size;i++){
        val_list[pren_id]=i;
        int res=enumerateVal(pren_list,pren_id+1,val_list,term1,term2,model_id);
        if (res!=-1)
            t+=res;
        if (pren_list[pren_id]==1){
            if (res==0) 
                return 0;       
        }else {
            if (res==1)
                return 1;
        }
    }
    if (t==0) return -1;
    return 1;
}
// int checkFormulaEQ(FORMULA formula1,){
    
// }
// void AddFormula(int *pren_list,TERM term1,TERM term2){
//     FORMULALIST now = Formula_List->cur;
//     for (int i=0;i<formula_num;i++){
//         //if (checkFormulaEQ(now,)) return;
//         now = now->next->cur;
//     }
//     FORMULA formula = (FORMULA)malloc(sizeof(struct Formula));
//     formula->term1 = term1;
//     formula->term2 = term2;
//     formula->pren_list = (int*)malloc(sizeof(int)*val_size);
//     for (int i=0;i<val_size;i++)
//     formula->pren_list[i] = pren_list[i];

//     formula_num+=1;
//     FORMULALIST formula_list = (FORMULALIST)malloc(sizeof(struct FormulaList));
//     formula_list->cur = formula;
//     formula_list->next = Formula_List;
//     Formula_List = formula_list;
// }
int checkByModel(int *pren_list,TERM term1,TERM term2){
    int *val_list;
    val_list=(int*)malloc(sizeof(int)*val_size);
    int res=0;
    for (int i=0;i<model_size;i++){
        //printf("model_id = %d\n",i);
        res += enumerateVal(pren_list,0,val_list,term1,term2,i);
    }
    if (res==model_size) {
        FILE* fp;
        fp = fopen("result.txt","a");
        for (int i=0;i<val_size;i++){
            if (pren_list[i]==1)
                fprintf(fp,"/forall %s ", Val_Table[i]->val_name);
            else if (pren_list[i]==0) fprintf(fp,"/exist %s ", Val_Table[i]->val_name);
        }
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
//pren=1表示任意，=0表示存在量词
int generatePREN(int id,int* pren_list,TERM term1,TERM term2,int* hasLit){
    if (id>val_size){
        int forall_sum=0;
        for (int i=0;i<val_size;i++)
            if (pren_list[i]==1) forall_sum+=1;
        // for (int i=0;i<val_size;i++){
        //     if (pren_list[i]==1)
        //         printf("/forall %s ", Val_Table[i]->val_name);
        //     else if (pren_list[i]==0) printf("/exist %s ", Val_Table[i]->val_name);
        // }
        // printTerm(term1);
        // printf(" = ");
        // printTerm(term2);
        // printf("\n");
        if (forall_sum>0)
            return checkByModel(pren_list,term1,term2);
        else return 0;
    }
    if (!hasLit[id]) {
        pren_list[id]=-1;
        return generatePREN(id+1,pren_list,term1,term2,hasLit); 
    }
    int flag;
    for (int i=1;i>=0;i--){
        if (i==0&&gen_exist==0) continue;  
        pren_list[id]=i;
        flag=generatePREN(id+1,pren_list,term1,term2,hasLit);
        if (flag&&i==1) return 0;
    }
    return flag;
}
//todo: 之后要将Formula建模成数据类型
void generateFormula(){
    int *hasLit=(int*)malloc(sizeof(int)*val_size);
    int* pren_list=(int*)malloc(sizeof(int)*val_size);


    for (int i1=1;i1<=max_depth;i1++){
        TERMLIST termlist1 = Term_Table[i1];
        for (int j1=0;j1<term_num[i1];j1++){
            memset(hasLit,0,sizeof(hasLit));
            TERM t1=termlist1->cur;
            for (int i2=0;i2<=i1;i2++){
                TERMLIST termlist2 = Term_Table[i2];
                for (int j2=0;j2<term_num[i2];j2++){
                    if (i2==i1&&j2==j1) break;
                    TERM t2=termlist2->cur;
                    for (_i=0;_i<val_size;_i++)
                        hasLit[_i]=0;
                    getLitInTerm(t1,hasLit);
                    getLitInTerm(t2,hasLit);
                    generatePREN(0,pren_list,t1,t2,hasLit);
                    termlist2=termlist2->next;
                }
            }
            termlist1=termlist1->next;
        }
    }
    free(hasLit);
    free(pren_list);
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
        if (term_num[depth]==0){
            Term_Table[depth]=(TERMLIST)malloc(sizeof(struct TermList));
            Term_Table[depth]->cur=t;
            Term_Table[depth]->next=NULL;
        }else {
            TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
            termlist->cur=t;
            termlist->next=NULL;
            TERMLIST cur=Term_Table[depth];
            memset(mp,-1,sizeof(mp));
            if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
            while (cur->next!=NULL){
                cur=cur->next;
                memset(mp,-1,sizeof(mp));
                if (depth>=2&&hasRewrite(cur->cur,termlist->cur)) return;
            }
            cur->next=termlist;
            // termlist->next = Term_Table[depth];
            // termlist->cur = term;
            // Term_Table[depth] = termlist;
        }
        // printf("get term : ");
        // printTerm(Term_Table[depth]->cur);
        // printf("\n");
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        TERMLIST termlist = Term_Table[i];
        for (int k=0;k<term_num[i];k++){
            term->para_list[para_idx] = termlist->cur;
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
            termlist = termlist->next;
        }
    }
}
void generateTerm(){
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
                if (term_num[i]==0){
                    Term_Table[i]=(TERMLIST)malloc(sizeof(struct TermList));
                    Term_Table[i]->cur=term;
                }else {
                    TERMLIST termlist=(TERMLIST)malloc(sizeof(struct TermList));
                    termlist->cur=term;
                    termlist->next=NULL;
                    TERMLIST cur=Term_Table[i];
                    while (cur->next!=NULL){
                       cur=cur->next;
                    }
                    cur->next=termlist;
                        //  termlist->next = Term_Table[i];
                        //  termlist->cur = term;
                        //  Term_Table[i] = termlist;
                }
                term_num[i]++;
            }
        }else {
            for (int j=0;j<def_size;j++){
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
        TERMLIST termlist = Term_Table[i];
        fp = fopen("result.txt","a");
        fprintf(fp,"dep = %d  ,  term_num has %d\n",i,term_num[i]);
        fclose(fp);
        for (int k=0;k<term_num[i];k++){
            printTerm(termlist->cur);
            fp = fopen("result.txt","a");
            fprintf(fp,"\n");
            fclose(fp);
            termlist = termlist->next;
        }
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
