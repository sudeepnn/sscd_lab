%{
#include<stdio.h>
#include<stdlib.h>
int state=0,comment=0;
%}
%%
"//".*\n	{comment++;}
"/*"	{state=1;}
"*/"	{if(state==1){
	comment++;
	state=0;
	}		
	}
.|\n	{if(state==0)
	fprintf(yyout,"%s",yytext);}
%%
int main(){
char infile[100],outfile[100];
printf("Enter the input file : ");
scanf("%s",infile);
printf("Enter the output file : ");
scanf("%s",outfile);
yyin=fopen(infile,"r");
yyout=fopen(outfile,"w");
yylex();
printf("TOtal comment is :%d ",comment);
}
