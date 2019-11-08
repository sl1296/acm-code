
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[25],sg[25];
int g(int x){
    int bo[100],i,j;
    if(sg[x]!=-1)return sg[x];
    memset(bo,0,sizeof(bo));
    for(i=1;i<x;i++)for(j=1;j<=i;j++)bo[g(i)^g(j)]=1;
    for(i=0;;i++)if(!bo[i])return sg[x]=i;
}
int main(){
    int t,n,i,ans,c,j,k;
    memset(sg,-1,sizeof(sg));
    sg[1]=0;
    for(i=2;i<23;i++)sg[i]=g(i);
    scanf("%d",&t);
    while(t--){
        ans=0;c=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]&1)ans^=sg[n-i+1];
        }
        for(i=1;i<=n;i++)for(j=i+1;j<=n;j++)for(k=j;k<=n;k++)if((ans^sg[n-i+1]^sg[n-j+1]^sg[n-k+1])==0){
            c++;
            if(c==1)printf("%d %d %d\n",i-1,j-1,k-1);
        }
        if(!c)printf("-1 -1 -1\n");
        printf("%d\n",c);
    }
    return 0;
}

