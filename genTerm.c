#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc.h>
#include "mcs_def.h"

void printTerm(TERM term){
    if (term->isfun==0){
        printf("%s",Def_Table[term->idx]->fun_name);
        return;
    }
    printf("%s(",Def_Table[term->idx]->fun_name);
    for (int i=0;i<term->para_size;i++){
        if (i>=1) printf(",");
        printTerm(term->para_list[i]);
    }
    printf(")");
}
void allocatePara(int depth,int nowdepth,int para_idx,int para_num,TERM term){
    if (para_idx>=para_num){
        if (nowdepth>0) return;
        TERM t=(TERM)malloc(sizeof(TERM));
        t->isfun=term->isfun;
        t->depth=term->depth;
        t->para_size=term->para_size;
        t->idx=term->idx;
        t->para_list = term->para_list;
        if (term_num[depth]==0)
            Term_Table[depth]->cur=term;
        else {
            TERMLIST termlist=(TERMLIST)malloc(sizeof(TERMLIST));
            termlist->next = Term_Table[depth];
            termlist->cur = term;
            Term_Table[depth] = termlist;
        }
        term_num[depth]++;
        return;
    }
    for (int i=nowdepth;i>=0;i--){
        TERMLIST termlist = Term_Table[i];
        for (int k=0;k<term_num[i];k++){
            term->para_list[para_idx] = termlist->cur;
            termlist = termlist->next;
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
        }
    }
}
void generateTerm(){
    for (int i=0;i<=max_depth;i++){
        for (int j=0;j<def_num;j++){
            if (i==0){
                int isfun=0;
                if (Def_Table[j]->para_size==0) {
                    TERM term=(TERM)malloc(sizeof(TERM));
                    term->isfun=0;
                    term->depth=0;
                    term->para_size=0;
                    term->idx=j;
                    if (term_num[i]==0)
                        Term_Table[i]->cur=term;
                    else {
                        TERMLIST termlist=(TERMLIST)malloc(sizeof(TERMLIST));
                        termlist->next = Term_Table[i];
                        termlist->cur = term;
                        Term_Table[i] = termlist;
                    }
                    term_num[i]++;
                }else {
                    TERM term=(TERM)malloc(sizeof(TERM));
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
    for (int i=0;i<=max_depth;i++){
        for (int j=0;j<term_num[i];j++){
             TERMLIST termlist = Term_Table[i];
            for (int k=0;k<term_num[i];k++){
                printTerm(termlist->cur);
                printf("\n");
                termlist = termlist->next;
            }
        }
    }
}
