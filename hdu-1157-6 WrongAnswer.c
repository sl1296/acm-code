
#include <stdio.h>
#define MAXLEN 10010
void main(){
int cows;
int i=0,j;
int milk[MAXLEN];
int count,med;
scanf("%d",&cows);
med=cows/2; //为下标
while(cows--)   scanf("%d",&milk[i++]); //0号要使用.beak时,cows==-1,i为牛数
for(cows=i,i=0;i<cows;i++){ //MARK!   搜索
for(j=0,count=0;j<cows;j++){
if(milk[i]>milk[j])  count++;
}//for
if(count==med)  break;
}//for
printf("%d",milk[i]); 
 return 0;
 }

