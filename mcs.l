%{
  #include <stdio.h>
  #include "mcs.tab.h"
  int lexerror(char *s);
%}
%%
")" {return RP;}
"(" {return LP;}
"=" {return EQ;}
"\%" {return Annotate;}
[A-Za-z\$_][A-Za-z0-9\$_]* {yylval.str=yytext;return STR;} 
[-\+\*/\\\^<>=`~\?@&\|!#']+ {yylval.str=yytext;return SP_STR;}
[0-9]+ {yylval.Intval=atoi(yytext);yylval.str=yytext;return INT;}
"," {return Split;}
"\." {return END;}
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