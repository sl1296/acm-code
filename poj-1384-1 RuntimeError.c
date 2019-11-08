
#include <stdio.h>
int main(){
    int t,n,e,f,p[510],w[510],dp[500],z,i,j,lp,lw;
    scanf("%d",&t);
    for(z=0;z<t;z++){
        scanf("%d%d%d",&e,&f,&n);
        for(i=0;i<n;i++)scanf("%d%d",&p[i],&w[i]);
        f-=e;
        dp[0]=0;
        for(i=1;i<=f;i++)dp[i]=2000000000;
        for(i=0;i<n;i++)for(lp=p[i],lw=w[i];lw<=f;lp<<=1,lw<<=1)for(j=f;j>=lw;j--)dp[j]=dp[j]>dp[j-lw]+lp?(dp[j-lw]+lp):dp[j];
        if(dp[f]==2000000000)printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n",dp[f]);
    }
    return 0;
}

