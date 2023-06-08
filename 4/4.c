#include<stdio.h>
#include<stdlib.h>
char a[20],stk[20],ac[20],act[20];
int i=0,j=0,k=0,z=0,c=0;
void calcu();
void main(){
puts("Grammer \nE:E+E\n|E*E\n|(E)\n|id");
gets(a);
c=strlen(a);
printf("Stack\tinput\taction\n");
strcpy(ac,"SHIFT-->");
for(i=0,k=0;j<c;i++,k++,j++){
if(a[j]=='i'&&a[j+1]=='d'){
stk[i]=a[j];
stk[i+1]=a[j+1];
stk[i+2]='\0';
a[j]=' ';
a[j+1]=' ';
printf("$%s\t%s$\t%s id\n",stk,a,ac);
calcu();
}
else{
stk[i]=a[j];
stk[i+1]='\0';
a[j]=' ';
printf("$%s\t%s$\t%s symbol\n",stk,a,ac);
calcu();
}
}

}
void calcu(){
strcpy(act,"REDUCCE TO E");
for(z=0;z<c;z++){
if(stk[z]=='i'&&stk[z+1]=='d'){
stk[z]='E';
stk[z+1]='\0';
printf("$%s\t%s$\t%s\n",stk,a,act);
j++;
}
}

for(z=0;z<c;z++){
if(stk[z]=='E'&&stk[z+1]=='+'&&stk[z+2]=='E'){
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("$%s\t%s$\t%s\n",stk,a,act);
i=i-2;
}
}

for(z=0;z<c;z++){
if(stk[z]=='E'&&stk[z+1]=='*'&&stk[z+2]=='E'){
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("$%s\t%s$\t%s\n",stk,a,act);
i=i-2;
}
}

for(z=0;z<c;z++){
if(stk[z]=='('&&stk[z+1]=='+'&&stk[z+2]==')'){
stk[z]='E';
stk[z+1]='\0';
stk[z+2]='\0';
printf("$%s\t%s$\t%s\n",stk,a,act);
i=i-2;
}
}


}
