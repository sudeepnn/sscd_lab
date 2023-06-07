%{
#include "y.tab.h"
extern int yylval;

%}
num [0-9]+
%%
{num}	{yylval=atoi(yytext);
	return num;}
[\+\-\*\/]	{return yytext[0];}
[)]	{return yytext[0];}
[(]	{return yytext[0];}
.	;
\n	return 0;
%%
