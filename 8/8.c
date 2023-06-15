#include<stdio.h>
#include<stdlib.h>
void main(){
int max[20][20],allo[20][20],need[20][20],avil[20],comp[20],safeseq[20];
int i,j,x,p,r,proc,cnt=0;
printf("Enter the no of process: ");
scanf("%d",&p);
for(i=0;i<p;i++)
comp[i]=0;
printf("Enter the no of resource: ");
scanf("%d",&r);
printf("Enter the  max matrix: \n");
for(i=0;i<p;i++){
printf("\nfor process %d: ",i);
for(j=0;j<r;j++)
scanf("%d",&max[i][j]);
}
printf("Enter the  allocation matrix: \n");
for(i=0;i<p;i++){
printf("\nfor process %d: ",i);
for(j=0;j<r;j++)
scanf("%d",&allo[i][j]);
}
printf("Enter the avalable resource: ");
for(j=0;j<r;j++)
scanf("%d",&avil[j]);


for(i=0;i<p;i++){
for(j=0;j<r;j++)
need[i][j]=max[i][j]-allo[i][j];
}
x=0;
do{
printf("Max matrix \tAllocation matrix\n");
for(i=0;i<p;i++){
for(j=0;j<r;j++)
printf("%d ",max[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d ",allo[i][j]);
printf("\n");
}

proc=-1;
for(i=x;i<p;i++){
	if(comp[i]==0){
		proc=i;
		for(j=0;j<r;j++){
			if(avil[j]<need[i][j]){
				proc=-1;
				break;
			}
		}
	}
	if(proc!=-1)
	break;
 }

if(proc!=-1){
printf("Process %d runs to completion",proc+1);
safeseq[cnt++]=proc+1;
for(j=0;j<r;j++){
avil[j]+=allo[proc][j];
max[proc][j]=0;
allo[proc][j]=0;
comp[proc]=1;
x=i;
if(i==p-1){
x=0;
}
}
}
}while(cnt!=p && proc!=-1);
if(cnt==p){
printf("system in safe sequence: \n");
for(j=0;j<r;j++)
printf("%d",safeseq[j]);
}
else
printf("system is not in safe sequence");
}


