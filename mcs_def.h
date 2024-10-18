#include <stdio.h>
#include <assert.h>
#include <vector>


#define MAX_N_DEF 1024
#define MAX_N_ASSIGN 1024
#define MAX_N_PARA 512
#define MAX_NAME_LEN 512
#define MAX_N_MODEL 1024
#define MAX_DEPTH 8


typedef struct InputAssign {
    int fun_idx;
    int para_size;
    //int* para_list;
    std::vector<int> para_list;
    int res;
} *INPUTASSIGN;

typedef struct Model{
//    struct Constant **Constant_Table;
//    int constant_size;
      std::vector<INPUTASSIGN> Assign_Table;
//    struct InputAssign **Assign_Table;
      int assign_size;
      int model_size;
}*MODEL;

typedef struct Def{
    int para_size;
    char *fun_name;
} *DEF;

typedef struct Term{
    int depth;
    int isfun;
    int idx;
    int para_size;
    struct Term **para_list; 
    //std::vector<Term*> para_list;
} *TERM;

// typedef struct TermList{
//     TERM cur;
//     struct TermList *next;
// }*TERMLIST;

// typedef struct Val{
//     char *val_name;
// }*VAL;

// typedef struct Constant{
//     char *const_name;
// }*CONSTANT;

typedef struct Formula{
    struct Term *term1;
    struct Term *term2;
    //int *pren_list;
}*FORMULA;

// typedef struct FormulaList{
//     FORMULA cur;
//     struct FormulaList *next;
// }*FORMULALIST;

std::vector<TERM> *Term_Table;
int *term_num;
//FORMULALIST Formula_List;
std::vector<FORMULA> Formula_List;

std::vector<MODEL> Model_Table;
std::vector<DEF> Def_Table;

// MODEL* Model_Table;
// VAL* Val_Table;
// DEF* Def_Table;

int val_size=3;
int max_depth=2;
int gen_exist=0;//0时不生成存在量词

//void generateTerm();
