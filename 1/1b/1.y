%{
#include<stdlib.h>
#include<stdio.h>
int yyerror();
int yylex();
int result=0;
%}
%token num;
%left '+' '-'
%left '*' '/'
%%
S:E	{result=$1;}
E:E '+' E	{$$=$1+$3;}
 |E '-' E	{$$=$1-$3;}
 |E '*' E	{$$=$1*$3;}
 |E '/' E	{if($3!=0){
 	$$=$1/$3;
 	}
 	else{
 	printf("devide by zero error");
 	exit(0);
 	}}
 |'(' E ')'	{$$=$2;}
 |num	{$$=$1;}
%%
int main(){
printf("Enterthe expression : ");
yyparse();
printf("REsult is %d:",result);
}
int yyerror(){

printf("Invalid expression");
exit(0);
}

