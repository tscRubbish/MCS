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
#include <boost/program_options.hpp>
#include "json.hpp"
#include <fstream> 
#include <cstdio>
#include <memory>
#include <array>

using json = nlohmann::json;

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
std::string PrvoerPath = "./bin/prover9 " ;

//void initNewModel();
int getDefByName(const char* s);
int getNameLength(char *s);
void printModel();
void printAssign();
void generateTerm();
void generateFormula();

// void initNewModel(){
//     cur_assign=0;
//     cur_model+=1;
// }

int getDefByName(std::string s){
    //printf("def size = %d\n",Def_Table.size());
    for (_i=0;_i<Def_Table.size();_i++){
            if (!s.compare(Def_Table[_i])){
                    return _i;
                    break;
            }
    }
    return -1;
}

void printAssign(){
    printf("printAssign\n");
    printf("\ncur_def = %d\n",cur_def);
    for (_i=0;_i<cur_def;_i++){
        printf("def id =%d : %s\n",_i,Def_Table[_i].c_str());
    }
    printf("Model id = %d\n Assign id = %d\n",cur_model,cur_assign);
    printf("para size = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->para_size);
    printf("def id = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx);
    printf("%s(",Def_Table[Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx].c_str());
    for (_i=0;_i<Model_Table[cur_model]->Assign_Table[cur_assign]->para_size;_i++){
        printf("%d,",Model_Table[cur_model]->Assign_Table[cur_assign]->para_list[_i]);
    }
    printf(") = %d\n",Model_Table[cur_model]->Assign_Table[cur_assign]->res);
 }

void printModel(){
    printf("printModel\n");
    // for (_i=0;_i<cur_constant;_i++){
    //     printf("Model id : %d , constant %s \n", cur_model, Model_Table[cur_model]->Constant_Table[_i]->const_name);
    // }
    for (_i=0;_i<cur_assign;_i++){
        printf("Assign is %s (", Def_Table[Model_Table[cur_model]->Assign_Table[_i]->fun_idx].c_str());
        for (_j=0;_j<Model_Table[cur_model]->Assign_Table[_i]->para_size;_j++){
            printf("%d ,",Model_Table[cur_model]->Assign_Table[_i]->para_list[_j]);
        }
        printf(" )= %d \n", Model_Table[cur_model]->Assign_Table[_i]->res);
    }
}
void printTermFile(TERM term,char * path){
    FILE* fp;
    fp = fopen(path,"a");
    if (term->isfun==0){
        fprintf(fp,"%s", Val_List[term->idx].c_str());
        fclose(fp);
        return;
    }
    if (term->para_size==0){
        fprintf(fp,"%s", Def_Table[term->idx].c_str());
        fclose(fp);
        return;
    }
    fprintf(fp,"%s(", Def_Table[term->idx].c_str());
    fclose(fp);
    for (int i=0;i<term->para_size;i++){
        if (term->para_list[i]==nullptr) return;
        fp = fopen(path,"a");
        if (i>=1) fprintf(fp,",");
        fclose(fp);
        printTermFile(term->para_list[i],path);
    }
    fp = fopen(path,"a");
    fprintf(fp,")");
    fclose(fp);
}
std::string printTerm(TERM term){
    if (term->isfun==0){
        return Val_List[term->idx];
    }
    if (term->para_size==0){
        return Def_Table[term->idx];
    }
    std::string str(Def_Table[term->idx]);
    str+="(";
    for (int i=0;i<term->para_size;i++){
        //if (term->para_list[i]==nullptr) return;
        if (i>=1) str+=",";
        str+=printTerm(term->para_list[i]);
    }
    str+=")";
    return str;
}
std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    
    return result;
}

int hasRename(TERM term1 ,TERM term2){
    if (term1->isfun!=term2->isfun) return 0;
    if (term1->isfun==0) {
        if (mp[term1->idx]>=0&&mp[term1->idx]!=term2->idx) return 0;
        mp[term1->idx]=term2->idx;
        return 1;
    }
    if (term1->para_size!=term2->para_size) return 0;
    if (term1->idx!=term2->idx) return 0;
    for (int i=0;i<term1->para_size;i++){
        if (!hasRename(term1->para_list[i],term2->para_list[i])) return 0;
    }
    return 1;
}

// bool matchRewrite(TERM term,RewriteRule rw){
//     if (term->isfun==0||term->para_size==0) return 0;
//     if (!rw.fun_name.compare(Def_Table[term->idx])){
        
//     }else {
//         for (int j=0;j<term->para_size;j++){
//             if (matchRewrite(term->para_list[j],rw)) return 1;
//         }
//     }
// }
bool checkRewrite(TERM term1){
    if (RewriteRules.size()==0) return false;
    std::ofstream outFile("tmp");
    if (outFile.is_open()) {
            outFile<<"set(paramodulation).\n"<<std::endl;
            // outFile<<"set(ordered_para).\n"<<std::endl;
            // outFile<<"clear(back_demod).\n"<<std::endl;
           outFile<<"formulas(assumptions).\n"<<std::endl;
           outFile<<RewriteRules<<std::endl;
           outFile<<"\nend_of_list.\n"<<std::endl;

           outFile<<"formulas(goals).\n"<<std::endl;
           outFile<<printTerm(term1);
           outFile<<" = ";
           outFile<<printTerm(term2)<<" .";
           outFile<<"\nend_of_list.";
           
           // 调用可执行文件并获取输出
            std::string output = exec("bin/prover9 -f tmp");

            // if (output.find("THEOREM PROVED")!=std::string::npos){
            //     return 1;
            // }else return 0;

            std::regex pattern("Demod_rewrites=(\\d+)."); // 正则表达式，提取数字
            std::smatch matches;
            if (std::regex_search(output, matches, pattern) && matches.size() > 1) {
                // matches[1] 包含提取的数字
                std::string numberStr = matches[1]; // 提取的数字字符串
                int number = std::stoi(numberStr);  // 转换为整数
                std::cout << "Extracted number: " << number << std::endl;
                return number>0;
            } else {
                return 0;
            }

    } else {
            std::cerr << "Unable to create file." << std::endl;
            return 0;
    }
    //std::remove("tmp");
}

int calculateByModel(TERM term,int *para_val_list,int model_id){
    for (int i=0;i<Model_Table[model_id]->Assign_Table.size();i++){
        if (Model_Table[model_id]->Assign_Table[i]->fun_idx==term->idx){
            int flag=1;
            for (int j=0;j<term->para_size;j++){
                //printf("para match %d %d\n",Model_Table[model_id]->Assign_Table[i]->para_list[j],para_val_list[j]);
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
        //printf("term %d value is %d\n",term->idx,val_list[term->idx]);
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
    //free(para_val_list);
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
    //std::cout<<res<<std::endl;
    if (res==cur_model) {
        return 1;
    }
    //free(val_list);
    return 0;
}

void generateFormula(){
    for (int i1=1;i1<=max_depth;i1++){
        for (int j1=0;j1<term_num[i1];j1++){
            for (int i2=0;i2<=i1;i2++){
                for (int j2=0;j2<term_num[i2];j2++){
                    if (i2==i1&&j2==j1) break;
                    int flag = checkByModel(Term_Table[i1][j1],Term_Table[i2][j2]);
                    //if (i1<=1&&i2<=1)
                    //printf("(%d,%d) (%d,%d) flag=%d\n",i1,j1,i2,j2,flag);
                    //std::cout<<printTerm(Term_Table[i1][j1])<<' '<<printTerm(Term_Table[i2][j2])<<' '<<flag<<std::endl;
                    if (flag){
                        //FORMULA f=(FORMULA)malloc(sizeof(struct Formula));
                        FORMULA f = new Formula();
                        f->term1 = Term_Table[i1][j1];
                        f->term2 = Term_Table[i2][j2];
                        Formula_List.push_back(f);
                        printTermFile(f->term1,outFile);

                        FILE* fp = fopen(outFile,"a");
                        fprintf(fp,"=");
                        fclose(fp); 

                        printTermFile(f->term2,outFile);

                        fp = fopen(outFile,"a");
                        fprintf(fp,"\n");
                        fclose(fp); 
                    }
                }
            }
        }
    }
}
void allocatePara(int depth,int nowdepth,int para_idx,int para_num,TERM term){
    //printf("allocate nowdep=%d para_idx=%d  para_num=%d\n",nowdepth,para_idx,para_num);
    if (para_idx>=para_num){
        if (nowdepth>0) return;
        //TERM t=(TERM)malloc(sizeof(struct Term));
        TERM t = new Term();
        t->isfun=term->isfun;
        t->depth=term->depth;
        t->para_size=term->para_size;
        t->idx=term->idx;
        t->para_list = (TERM*)malloc(sizeof(TERM)*term->para_size);
        for (int i=0;i<term->para_size;i++){
            t->para_list[i]=term->para_list[i];
        }
        // for (int j=0;j<Rule_List.size();j++)
        //     if (matchRewrite(t,Rule_List[j])) return;

        // for (int i=0;i<=depth;i++)
        //     for (int j=0;j<term_num[i];j++){
        //         if (checkRewrite(t,Term_Table[i][j])) {return;}
        //     }
        if (checkRewrite(t)) return ;
        for (int j=0;j<term_num[depth];j++){
            memset(mp,-1,sizeof(mp));
            //if (depth>=2&&hasRename(Term_Table[depth][j],t)) return;
            if (hasRename(Term_Table[depth][j],t)) {return;}
        } 
        //printTerm(t);
        Term_Table[depth].push_back(t);
        term_num[depth]++;
        return;
    }

    for (int i=nowdepth;i>=0;i--){
        for (int k=0;k<term_num[i];k++){
            //printf("term_num %d : %d\n",i,term_num[i]);
            //printTerm(Term_Table[i][k]);
            term->para_list[para_idx]=Term_Table[i][k];
            allocatePara(depth,nowdepth-i,para_idx+1,para_num,term);
        }
    }
}

void generateTerm(){
    //Term_Table = malloc(sizeof(std::vector<TERM> )*max_depth);
    Term_Table = new std::vector<TERM> [max_depth+1];
    term_num = (int*)malloc(sizeof(int)*(max_depth+1));
    memset(term_num,0,sizeof(term_num));
    for (int i=0;i<=max_depth;i++){
        printf("i=%d\n",i);
        if (i==0){
            for (int j=0;j<val_size;j++){
                printf("j=%d\n",j);
                //TERM term=(TERM)malloc(sizeof(struct Term));
                TERM term = new Term();
                term->isfun=0;
                term->depth=0;
                term->para_size=0;
                term->idx=j;
                //printTerm(term);
                Term_Table[i].push_back(term);
                term_num[i]++;
            }
            // for (int j=0;j<cur_def;j++){
            //     if (Def_para_size[j]==0){
            //         printf("Constant : id = %d , cname = %s\n",j,Def_Table[j].c_str());
            //         //TERM term=(TERM)malloc(sizeof(struct Term));
            //         TERM term = new Term();
            //         term->isfun=1;
            //         term->depth=0;
            //         term->para_size=0;
            //         term->idx=j;
            //         Term_Table[i].push_back(term);
            //         term_num[i]++;
            //     }
            // }
        }else {
            for (int j=0;j<cur_def;j++){
                if (Def_para_size[j]>=0){
                    //TERM term=(TERM)malloc(sizeof(struct Term));
                    TERM term = new Term();
                    term->isfun=1;
                    term->depth=i;
                    term->para_size=Def_para_size[j];
                    term->idx=j;
                    //term->para_list=(TERM*)malloc(sizeof(TERM)*term->para_size);
                    term->para_list = new TERM [term->para_size];
                    allocatePara(i,i-1,0,term->para_size,term);
                    //free(term->para_list);
                    //free(term);
                }
            }
        }
    }

    FILE* fp;
    for (int i=0;i<=max_depth;i++){
        fp = fopen(outFile,"a");
        fprintf(fp,"dep = %d  ,has term num = %d\n",i,term_num[i]);
        fclose(fp);
        for (int k=0;k<term_num[i];k++){
            printTermFile(Term_Table[i][k],outFile);
             fp = fopen(outFile,"a");
             fprintf(fp,"\n");
             fclose(fp);
        }
    }
    fp = fopen(outFile,"a");
    fprintf(fp,"\n");
    fclose(fp);
}
std::vector<int> getnumberList(std::string str){
    std::regex regex("\\d+"); // 正则表达式匹配数字
    std::sregex_iterator it(str.begin(), str.end(), regex);
    std::sregex_iterator end;
    std::vector<int> numberlist;

    while (it != end) {
        numberlist.push_back(std::stoi(it->str()));
        ++it;
    }
    return numberlist;
}

std::string getfunName(std::string str){
    std::string pattern = R"([A-Za-z\$_][A-Za-z0-9\$_]*|[-\+\*/\\\^<>=`~\?@&\|!#']+)";
    std::regex regexPattern(pattern);
    std::sregex_iterator it(str.begin(), str.end(), regexPattern);
    //std::sregex_iterator end;
    return it->str();
}

void getModelAssign(std::string str){
    size_t posLP = str.find('(');
    if (posLP != std::string::npos){
        std::string funcName = str.substr(0, posLP);
        std::cout<< "fun_name = "<<funcName<<"()"<<std::endl;
    

        size_t paramStart = posLP + 1;
        size_t paramEnd = str.find(')'); // 找到右括号
        std::string params = str.substr(paramStart, paramEnd - paramStart); // 提取参数部分

        size_t resultStart = str.find('=') + 1; // 找到等号后面的数字
        std::string result = str.substr(resultStart); // 提取结果

        std::vector<int> paraList = getnumberList(params);
        printf("para size = %d\n",paraList.size());

        int idx=getDefByName(funcName);
        if (idx==-1) {
            createDef=true;
            //DEF def=(DEF)malloc(sizeof(struct Def));    
            //DEF def = new Def();        
            // def->fun_name=(char*) malloc(sizeof(char)*funcName.length());
            // strcpy(def->fun_name , funcName.c_str());
            //def->fun_name = funcName.c_str();
            printf("def name = %s\n",funcName.c_str());
            Def_Table.push_back(funcName);
            Def_para_size.push_back(paraList.size());
            //Def_Table[cur_def]->para_size=paraList.size();
            cur_def++;
        }

        //INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        INPUTASSIGN input=new InputAssign();
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = idx==-1?cur_def-1:idx;
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = paraList.size();
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_list = paraList;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = getnumberList(result)[0];

    }else {
        std::string funcName = str.substr(0, str.find('=')-1);


        size_t resultStart = str.find('=') + 1; // 找到等号后面的数字
        std::string result = str.substr(resultStart); // 提取结果

        int idx=getDefByName(funcName);
        if (idx==-1) {
            //DEF def=(DEF)malloc(sizeof(struct Def));
            //DEF def = new Def();
            // def->fun_name=(char*) malloc(sizeof(char)*funcName.length());
            // strcpy(def->fun_name , funcName.c_str());
            //def->fun_name = funcName.c_str();
            printf("def name = %s\n",funcName.c_str());
            Def_Table.push_back(funcName);
            Def_para_size.push_back(0);
            //Def_Table[cur_def]->para_size=0;
            cur_def++;
        }

        //INPUTASSIGN input=(INPUTASSIGN)malloc(sizeof(struct InputAssign));
        INPUTASSIGN input = new InputAssign();
        Model_Table[cur_model]->Assign_Table.push_back(input);
        Model_Table[cur_model]->Assign_Table[cur_assign]->fun_idx = idx==-1?cur_def-1:idx;
        Model_Table[cur_model]->Assign_Table[cur_assign]->para_size = 0;
        //Model_Table[cur_model]->Assign_Table[cur_assign]->para_list = pa;
        Model_Table[cur_model]->Assign_Table[cur_assign]->res = getnumberList(result)[0];
    }

    printAssign();
    cur_assign++;
}

void readModelFromFile(char *path){
    std::ifstream inputFile(path); // 打开文件

    // 检查文件是否成功打开
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
    }

    std::string line;
    
    bool has_model=false;
    // 逐行读取文件
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl; // 输出每一行
        size_t posAnnote = line.find('%');
        if (posAnnote != std::string::npos){
            if (line.find("size") != std::string::npos){
                if (has_model) {
                    printModel();
                    cur_model++;
                }
                cur_assign = 0;
                //MODEL model=(MODEL)malloc(sizeof(struct Model));
                MODEL model = new Model();
                Model_Table.push_back(model);
                Model_Table[cur_model]->model_size=getnumberList(line)[0];
                printf("model size = %d\n",Model_Table[cur_model]->model_size);
                has_model=true;
            }
        }
        if (line.find('.') != std::string::npos){
            if (Model_Table[cur_model]->model_size <= 0){
                std::cerr << "Error input Format : has not size ." << std::endl;
            }
            getModelAssign(line);
        }
    }
    printModel();
    cur_model++;
    inputFile.close();
}


// // 递归解析参数
// Parameter parseParameter(const nlohmann::json& item) {
//     if (item.is_string()) {
//         return item.get<std::string>();
//     } else if (item.is_object()){
//         RewriteRule rule;
//         rule.fun_name = item["fun_name"];
//         //rule.para = item["para"].get<std::vector<Parameter>>();
//         // 解析 para 字段
//         for (const auto& param : item.at("para")) {
//             rule.para.push_back(parseParameter(param));
//         }
//         return rule;
//     }else throw std::invalid_argument("Invalid parameter type");
// }

// // 解析 JSON
// std::vector<RewriteRule> parseJson(const std::string& jsonData) {
//     nlohmann::json jsonArray = nlohmann::json::parse(jsonData);
//     std::vector<RewriteRule> rewriteRules;

//     for (const auto& item : jsonArray) {
//         RewriteRule rule;
//         rule.fun_name = item["fun_name"];
//         rule.res = item.at("res").get<std::string>();
        
//         // 解析 para 字段
//         for (const auto& param : item["para"]) {
//             rule.para.push_back(parseParameter(param));
//         }
        
//        rewriteRules.push_back(rule);
//     }
    
//     return rewriteRules;
// }

// // 输出重写规则
// void printRewriteRule(const RewriteRule& rule) {
//     std::cout << "Function Name: " << rule.fun_name << "\nParameters: ";
//     for (const auto& param : rule.para) {
//         if (std::holds_alternative<std::string>(param)) {
//             std::cout << std::get<std::string>(param) << " ";
//         } else {
//             printRewriteRule(std::get<RewriteRule>(param)); // 递归输出
//         }
//     }
//     std::cout << "\nRewrite res: " << rule.res;
//     std::cout << std::endl;
// }

int main(int argc, char **argv) {
    namespace po = boost::program_options;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("help,h", "Show help message")
        //("config,c", po::value<std::string>(), "use Conifg file for input")
        ("input,i", po::value<std::string>(), "Input file path")
        ("output,o", po::value<std::string>(), "Output file path")
        ("maxdepth,d", po::value<int>(),"max depth for generate term")
        ("value,v",po::value<std::string>(),"value list")
        ("rewrite,rw", po::value<std::string>(),"rewrite rule");
        
    // 解析命令行参数
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // 显示帮助信息
    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    // 处理参数
    if (vm.count("input")) {
        std::cout << "Input file : " << vm["input"].as<std::string>() << std::endl;
        // 创建一个足够大的 char 数组
        inputFile = new char[vm["input"].as<std::string>().size() + 1]; // +1 用于 null terminator
        // 复制内容
        std::strcpy(inputFile, vm["input"].as<std::string>().c_str());
    }
    if (vm.count("output")) {
        std::cout << "Output file: " << vm["output"].as<std::string>() << std::endl;
        outFile = new char[vm["output"].as<std::string>().size() + 1]; 
        std::strcpy(outFile, vm["output"].as<std::string>().c_str());
    }
    if (vm.count("maxdepth")) {
        std::cout << "maxdepth : " <<vm["maxdepth"].as<int>()<< std::endl;
        max_depth=vm["maxdepth"].as<int>();
    }

    if (vm.count("value")) {
        std::cout << "value : " <<vm["value"].as<std::string>()<< std::endl;
        //std::string =vm["value"].as<std::string>();
        //todo:get value list and size
        json jsonObject = json::parse(vm["value"].as<std::string>());
        // 将 JSON 数组转换为 std::vector<std::string>
        Val_List = jsonObject.get<std::vector<std::string>>();
        val_size = Val_List.size();

        // 输出结果
        std::cout << "val size = "<<val_size<<" content:\n";
        for (const auto& str : Val_List) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }

    RewriteRules = "";
    if (vm.count("rewrite")) {
        std::cout << "rewrite : " <<vm["rewrite"].as<std::string>()<< std::endl;
        // Rule_List = parseJson(vm["rewrite"].as<std::string>());
        // // 输出结果
        // for (const auto& rule : Rule_List) {
        //     printRewriteRule(rule);
        // }
        RewriteRules = vm["rewrite"].as<std::string>();
    }



    FILE* fp = fopen(outFile,"w");
    fprintf(fp,"");
    fclose(fp);
    readModelFromFile(inputFile);
    generateTerm(); 
    // int *val_list;
    // val_list=(int*)malloc(sizeof(int)*val_size);
    // val_list[0]=0;val_list[1]=0;val_list[2]=0;
    //printf("test getResult =%d\n",getResult(Term_Table[1][0],val_list,0));
    fp = fopen(outFile,"a");
    fprintf(fp,"\nGenerate Formulas : \n");
    fclose(fp);
    generateFormula();
    fp = fopen(outFile,"a");
    fprintf(fp,"Has Generated %d Formulas : \n",Formula_List.size());
    fclose(fp);
}
