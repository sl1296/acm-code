
#include <stdio.h>
__int64 a[20],b[20];
//FILE *fp;
void find(int num,int node){
  //  printf("\n%d %d\n",num,node);
    __int64 l;
    int i,left,right;
    if(node==1){
        printf("X");return;
    }
    node--;
    for(i=0;i<node;i++){
        l=a[i]*a[node-i];
        if(num<=l)break;
        num-=l;
    }
  //  printf("%d %d %d\n",num,i,node-i);
    left=(num+a[node-i]-1)/a[node-i];
    right=num%a[node-i];
    if(right==0 && node-i>1){
        right=a[node-i];
    }
    if(i>0){
        printf("(");
        find(left,i);
        printf(")");
    }
    printf("X");
    if(node-i>0){
        printf("(");
        find(right,node-i);
        printf(")");
    }
}
int main(){
  //  fp=fopen("oout.txt","w+");
    int i,n;
    b[1]=a[1]=1;b[2]=a[2]=2;b[0]=a[0]=1;
    for(i=3;i<20;i++)b[i]=a[i]=(4*i-2)*a[i-1]/(i+1);
    for(i=2;i<20;i++)b[i]+=b[i-1];
  //  for(i=0;i<20;i++)printf("%I64d ",a[i]);printf("\n");
  //  for(i=0;i<20;i++)printf("%I64d ",b[i]);printf("\n");
   // for(n=1;n<10000000;n++){
    while(1){
        scanf("%d",&n);
    // n=45;
    // fprintf(fp,"%d\n",n);
        if(!n)break;
        for(i=18;i>0;i--)if(n>b[i])break;
        find(n-b[i],i+1);
        printf("\n");
    }
   // fclose(fp);
    return 0;
}

