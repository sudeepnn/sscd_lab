#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char prod[3][10]={"A->aBa","B->bB","b->@"};
char first[3][10]={"a","b","@"};
char follow[3][10]={"$","a","a"};
char table[3][4][10];

char input[20];
char stack[20];
int top=-1;
char curp[20];
void push(char item){
stack[++top]=item;
}

void pop(){
top=top-1;
}

void display(){
for(int i=top;i>0;i--)
printf("%c",stack[i]);
}
int num(char ch){
switch(ch){
case 'A':return 1;
case 'B':return 2;
case 'a':return 1;
case 'b':return 2;
case '@':return 3;
}
return 1;
}
void main(){
int i=0,j=0,k=0,n=0;
for(i=0;i<3;i++)
for(j=0;j<4;j++){
strcpy(table[i][j],"EMPTY");
}

printf("Grammer: \n");
for(i=0;i<3;i++)
printf("%s\n",prod[i]);

printf("first{%s,%s,%s}\n",first[0],first[1],first[2]);
printf("Follow{%s,%s}\n",follow[0],follow[1]);
printf("Predictive parsing table: ");
strcpy(table[0][0],"");
strcpy(table[0][1],"a");
strcpy(table[0][2],"b");
strcpy(table[0][3],"$");
strcpy(table[1][0],"A");
strcpy(table[2][0],"B");

for(i=0;i<3;i++){
if(first[i][0]!='@')
strcpy(table[num(prod[i][0])][num(first[i][0])],prod[i]);
else
strcpy(table[num(prod[i][0])][num(follow[i][0])],prod[i]);
}
printf("\n----------------------------------------------------\n");
for(i=0;i<3;i++)
for(j=0;j<4;j++){
printf("%-30s",table[i][j]);
if(j==3)
printf("\n----------------------------------------------------\n");
}

printf("Enter the input string: ");
scanf("%s",input);
for(i=0;input[i]!='\0';i++)
if(input[i]!='a'&&input[i]!='b'&&input[i]!='$'){
printf("invalid");
exit(0);
}
if(input[i-1]!='$'){
printf("invalid");
exit(0);
}
push('$');
push('A');
i=0;
printf("\nSTACK\tINPUT\tACTION\n");
while(stack[top]!='$'&&input[i]!='$'){
	display();
	printf("\t%s\t",input+i);
		if(stack[top]==input[i]){
		printf("matched input %c\n",input[i]);
		pop();
		i++;
		}
		else{
			if(stack[top]>=65&&stack[top]<=92){
			strcpy(curp,table[num(stack[top])][num(input[i])]);
			if(!strcmp(curp,"e")){
			printf("invlaid");
			exit(0);
			}
			else{
			printf("Aplly production %s\n",curp);
				if(curp[3]=='@'){
					pop();
				}
				else{
					pop();
					n=strlen(curp);
					for(j=n-1;j>=3;j--)
					push(curp[j]);
				}
			}
		}
	}
}
display();
printf("\t%s\t",input+i);
if(stack[top]=='$'&&input[i]=='$')
printf("vaid ");
else
printf("invalidvaid ");
}
