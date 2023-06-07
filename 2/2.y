%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B;
%%
S:E B|B
E:E A|A
%%
int main(){
printf("Enter the input : ");
yyparse();
printf("valid input");
}
int yyerror(){
printf("Invalid input");
exit(0);
}
