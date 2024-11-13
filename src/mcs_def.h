#include <stdio.h>
#include <assert.h>
#include <vector>
#include <string>
#include <variant>


#define MAX_N_DEF 1024
#define MAX_N_ASSIGN 1024
#define MAX_N_PARA 512
#define MAX_NAME_LEN 512
#define MAX_N_MODEL 1024
#define MAX_DEPTH 8


typedef struct InputAssign {
    int fun_idx;
    int para_size;
    std::vector<int> para_list;
    int res;
} *INPUTASSIGN;

typedef struct Model{
      std::vector<INPUTASSIGN> Assign_Table;
      //int assign_size;
      int model_size;
}*MODEL;

// typedef struct Def{
//     int para_size=0;
//     const char* fun_name;
// } *DEF;

typedef struct Term{
    int depth;
    int isfun;
    int idx;
    int para_size;
    struct Term **para_list; 
} *TERM;


typedef struct Formula{
    struct Term *term1;
    struct Term *term2;
}*FORMULA;

// struct RewriteRule; // 前向声明

// using Parameter = std::variant<std::string, RewriteRule>;

// struct RewriteRule {
//     std::string fun_name;
//     std::vector<Parameter> para;
//     std::string res;
// };


std::vector<TERM> *Term_Table;
int *term_num;
std::vector<FORMULA> Formula_List;

std::vector<MODEL> Model_Table;
std::vector<std::string> Def_Table;
std::vector<int> Def_para_size;

std::vector<std::string> Val_List;
//std::vector<RewriteRule> Rule_List;
std::string RewriteRules;

int val_size=2;
int max_depth=2;
int gen_exist=0;//0时不生成存在量词
char* outFile="result";
bool needProve = false;
char* inputFile;

