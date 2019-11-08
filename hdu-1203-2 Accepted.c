
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int v,n,x[10010],i,j;
    double dp[10010],va[10010];
    while(1){
        scanf("%d%d",&v,&n);
        if(!v && !n)break;
        for(i=0;i<n;i++)scanf("%d%lf",&x[i],&va[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<n;i++)for(j=v;j>=x[i];j--)dp[j]=dp[j]>va[i]+(1-va[i])*dp[j-x[i]]?dp[j]:(va[i]+(1-va[i])*dp[j-x[i]]);
        printf("%.1lf%%\n",dp[v]*100);
    }
    return 0;
}

