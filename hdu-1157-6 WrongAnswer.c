
#include <stdio.h>
#define MAXLEN 10010
void main(){
int cows;
int i=0,j;
int milk[MAXLEN];
int count,med;
scanf("%d",&cows);
med=cows/2; //Ϊ�±�
while(cows--)   scanf("%d",&milk[i++]); //0��Ҫʹ��.beakʱ,cows==-1,iΪţ��
for(cows=i,i=0;i<cows;i++){ //MARK!   ����
for(j=0,count=0;j<cows;j++){
if(milk[i]>milk[j])  count++;
}//for
if(count==med)  break;
}//for
printf("%d",milk[i]); 
 return 0;
 }

