
#include<cstdio>
#define ll long long
ll dp[80][3];
ll re[80];
int main(){
    dp[1][0]=dp[1][2]=1;
    re[1]=1;
    for(int i=2;i<61;i++){
        dp[i][0]=dp[i-1][2];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][1]+dp[i-1][2];
        re[i]=dp[i][0]+dp[i][1]+dp[i][2]-1;
    }
    int n;
    while(~scanf("%d",&n)){
        printf("%lld\n",re[n]);
    }
    return 0;
}

