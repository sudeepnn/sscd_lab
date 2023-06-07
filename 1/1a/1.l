%{
#include<stdlib.h>
#include<stdio.h>
int op=0,idn=0 ,top=-1;
char stack[20],opary[20];
int idnary[20];
%}
%%
[0-9]+	{idnary[idn++]=atoi(yytext);}
"+"	{opary[op++]='+';}
"*"	{opary[op++]='*';}
"("	{stack[++top]='(';}
")"	{if(stack[top]=='(' )
	{
	top--;
	}
	else{
	printf("Invalid  input ");
	exit(0);
	}
	}
%%
void main(){
printf("Enter the string: ");
yylex();
if(top==-1 && idn==(op+1)){
printf("oprators are : ");
for(int i=0;i<op;i++)
printf("%c ",opary[i]);
printf("\n");

printf("identifires are : ");
for(int i=0;i<idn;i++)
printf("%d ",idnary[i]);
printf("\n");

printf("opratour count : %d",op);
printf("Indentifire count: %d",idn);
}
else
{
printf("Invalid  input ");
}
}
