
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    int t,n,m,p[110],h[110],c[110],z,i,j,dp[110],lc,lk,lp,lh;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)scanf("%d%d%d",&p[i],&h[i],&c[i]);
        memset(dp,0,sizeof(dp));
        for(i=0;i<m;i++){
            lc=c[i];
            for(lk=1;lc>0;lk<<=1){
                lc-=lk;
                if(lc<0)lk+=lc;
                lp=p[i]*lk;
                lh=h[i]*lk;
                for(j=n;j>=lp;j--)dp[j]=dp[j]>dp[j-lp]+lh?dp[j]:(dp[j-lp]+lh);
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

