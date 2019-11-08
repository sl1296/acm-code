
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int t,n,v,va[1010],x[1010],dp[1010],z,i,j;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        scanf("%d%d",&n,&v);
        for(i=0;i<n;i++)scanf("%d",&va[i]);
        for(i=0;i<n;i++)scanf("%d",&x[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)for(j=v;j>=x[i];j--)dp[j]=dp[j]>dp[j-x[i]]+va[i]?dp[j]:(dp[j-x[i]]+va[i]);
        printf("%d\n",dp[v]);
    }
    return 0;
}

