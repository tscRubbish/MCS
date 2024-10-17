%{
  #include <stdio.h>
  #include "mcs.tab.h"
  int lexerror(char *s);
%}
%%
"MODEL SIZE=" {return ModelSize;}
"TERM DEPTH=" {return TermDepth;}
"VAL SIZE=" {return ValSize;}
"DEF SIZE=" {return DefSize;}
"CONSTANT SIZE=" {return ConstantSize;}
"ASSIGN SIZE=" {return AssignSize;}
"#" {return ModelSplit;}
")" {return RFun;}
"(" {return LFun;}
"=" {return EQ;}
[A-Za-z]+ {yylval.str=yytext;return STR;} 
[0-9]+ {yylval.Intval=atoi(yytext);yylval.str=yytext;return INT_NUMBER;}
"," {return Split;}
"%" {return DefSplit;}
"." {return End;}
";" {return ResSplit;}
[\r\n] ;
[ \t] ;

%%
int lexerror(char *s){
  fprintf(stderr,"lexical error: %s\n", s);
}
int yywrap(void)
{
  return 1;
}
//int main()
//{
//  int tok;
//   while(tok = yylex()) {
//        
//    }
//}