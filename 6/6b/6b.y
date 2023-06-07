%{
#include<stdio.h>
#include<stdlib.h>
extern FILE* yyin;
int opc=0,idenc=0,digitc=0,keywordc=0;

%}
%token digit op keyword iden
%%
S:keyword S	{keywordc++;}
 |digit S	{digitc++;}
 |op S	{opc++;}
 |iden S	{idenc++;}
 |keyword	{keywordc++;}
 |digit	{digitc++;}
 |op	{opc++;}
 |iden	{idenc++;}
%%
int main(){
char file[100];
printf("Enetr the inout file: ");
scanf("%s",file);
yyin=fopen(file,"r");
do{
yyparse();}while(!feof(yyin));
printf("\noperator count: %d\n",opc);
printf("identifier count: %d\n",idenc);
printf("keyword count: %d\n",keywordc);
printf("dgit count: %d\n",digitc);
}
int yyerror(){
printf("try again");
exit(0);
}
