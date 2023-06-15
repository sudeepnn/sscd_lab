#include<stdio.h>
#include<stdlib.h>
void FIFO(char s[],char F[],int,int);
void LRU(char s[],char F[],int,int);
void main(){
int yn,ch,f,l;
char s[25],F[25];
printf("Frame: ");
scanf("%d",&f);
printf("String len: ");
scanf("%d",&l);
printf("String: ");
scanf("%s",s);
for(int i=0;i<f;i++)
F[i]=-1;
do{
printf("1.FIFO\n2.LUR\n3.exit");
scanf("%d",&ch);
switch(ch){
case 1:for(int i=0;i<f;i++)
F[i]=-1;
FIFO(s,F,l,f);
break;
case 2:for(int i=0;i<f;i++)
F[i]=-1;
LRU(s,F,l,f);
break;
case 3:
exit(0);
}
printf("1. to continue to exit press 0: ");
scanf("%d",&yn);
}while(yn);
exit(0);
}
void FIFO(char s[25],char F[25],int l,int f){
int i=0,j=0,k=0,cnt=0,flag=0;
printf("PAge\tFrame\tfault\n");
for(i=0;i<l;i++){
for(k=0;k<f;k++)
if(s[i]==F[k])
flag=1;
if(flag==0){
printf("%c\t",s[i]);
F[j]=s[i];
j++;
for(k=0;k<f;k++)
printf("%c ",F[k]);
printf("\tPage falut %d\n",cnt++);
}
else{
flag=0;
printf("%c\t",s[i]);
for(k=0;k<f;k++)
printf("%c ",F[k]);
printf("\tno Page falut \n");
}
if(j==f)
j=0;
}
}

void LRU(char s[25],char F[25],int l,int f){
int top=0,m=0,i=0,j=0,k=0,cnt=0,flag=0;
printf("Page\tFrame\tfault\n");
for(i=0;i<l;i++){
for(k=0;k<f;k++){
if(s[i]==F[k]){
flag=1;
break;
}
}
printf("%c\t",s[i]);

if(j!=f && flag==0){
F[top]=s[i];
j++;
if(j!=f)
top++;
}
else{
if(flag==0){
for(k=0;k<top;k++)
F[k]=F[k+1];
F[top]=s[i];
}
if(flag==1){
for(m=k;m<top;m++)
F[m]=F[m+1];
F[top]=s[i];
}
}
for(k=0;k<f;k++)
printf(" %c",F[k]);

if(flag==0)
printf("\tPage falut %d\n",cnt++);
else
printf("\tno Page falut \n");
flag=0;
}
}
