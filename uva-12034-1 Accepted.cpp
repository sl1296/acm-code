
#include <stdio.h>
int dp[1010][1010];
int main(){
    int t,z,n,r,i,j;
    scanf("%d",&t);
    for(i=1;i<1001;i++)dp[i][1]=1;
    for(i=2;i<1001;i++)for(j=2;j<=i;j++)dp[i][j]=(j*(dp[i-1][j]+dp[i-1][j-1]))%10056;
    for(z=1;z<=t;z++){
        scanf("%d",&n);
        r=0;
        for(i=1;i<=n;i++)r=(r+dp[n][i])%10056;
        printf("Case %d: %d\n",z,r);
    }
    return 0;
}

