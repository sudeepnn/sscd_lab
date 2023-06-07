%{
#include "y.tab.h"
extern int yylval;
%}
%%
[ \t]	;
[\+\-\*\/\=\<\>]	{printf("oprator is : %s\n",yytext);
			return op;}
int|float|char|main|void|printf	{printf("keyword: %s\n",yytext);return keyword;}
[0-9]+	{yylval=atoi(yytext);printf("Number is %s\n",yytext);return digit;}
[_A-Za-z][a-zA-z0-9]*	{printf("idnetifier is %s\n",yytext);return iden;}
.|\n	;
%%
