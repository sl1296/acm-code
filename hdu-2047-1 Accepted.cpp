
#include <stdio.h>
__int64 dp[45][4];
int main(){
    int i,n;
    dp[1][0]=1;
    dp[1][1]=2;
    dp[1][2]=3;
    for(i=2;i<41;i++){
        dp[i][0]=dp[i-1][1];
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])*2;
        dp[i][2]=dp[i][0]+dp[i][1];
    }
    while(scanf("%d",&n)!=EOF)printf("%I64d\n",dp[n][2]);
    return 0;
}

