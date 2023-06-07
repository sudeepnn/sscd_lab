#include<stdio.h>
#include<string.h>
char op[5],arg1[10],arg2[10],result[10];
void main(){
FILE *infile,*outfile;
infile=fopen("input.txt","r");
outfile=fopen("out.txt","w");
while(!feof(infile)){
fscanf(infile,"%s %s %s %s ",result,arg1,op,arg2);
if(strcmp(op,"+")==0){
fprintf(outfile,"MOV R0  %s\n",arg1);
fprintf(outfile,"ADD R0  %s\n",arg2);
fprintf(outfile,"MOV %s  R0\n",result);
}

if(strcmp(op,"=")==0){
fprintf(outfile,"MOV R0  %s\n",arg1);
fprintf(outfile,"MOV %s  R0\n",result);
}


if(strcmp(op,"-")==0){
fprintf(outfile,"MOV R0  %s\n",arg1);
fprintf(outfile,"SUB R0  %s\n",arg2);
fprintf(outfile,"MOV %s  R0\n",result);
}

if(strcmp(op,"*")==0){
fprintf(outfile,"MOV R0  %s\n",arg1);
fprintf(outfile,"MUL R0  %s\n",arg2);
fprintf(outfile,"MOV %s  R0\n",result);
}

if(strcmp(op,"/")==0){
fprintf(outfile,"MOV R0  %s\n",arg1);
fprintf(outfile,"DIV R0  %s\n",arg2);
fprintf(outfile,"MOV %s  R0\n",result);
}
}
}
