
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int tt[1001],c[1001],z[1001][1001],k;
int g(int x){
    int mex[1001],i;
    memset(mex,0,sizeof(mex));
    if(tt[x]!=-1)return tt[x];
    for(i=0;i<c[x];i++)mex[g(z[x][i])]=1;
    for(i=0;;i++)if(!mex[i])return tt[x]=i;
}
int main(){
    int n,a,ans,i,j;
    while(scanf("%d",&k)!=EOF){
        memset(tt,-1,sizeof(tt));
        for(i=0;i<k;i++){
            scanf("%d",&c[i]);
            for(j=0;j<c[i];j++)scanf("%d",&z[i][j]);
        }
        while(1){
            ans=0;
            scanf("%d",&n);
            if(!n)break;
            for(i=0;i<n;i++){
                scanf("%d",&a);
                ans^=g(a);
            }
            if(!ans)printf("LOSE\n"); else printf("WIN\n");
        }
    }
    return 0;
}

