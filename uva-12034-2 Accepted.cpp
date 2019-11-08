
#include<cstdio>
const int mod=10056;
int dp[1010][1010];
int ans[1010]={0,1};
int main(){
    dp[1][1]=1;
    for(int i=2;i<1005;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=(dp[i-1][j]*j%mod+dp[i-1][j-1]*j%mod)%mod;
            ans[i]=(ans[i]+dp[i][j])%mod;
        }
    }
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        printf("Case %d: %d\n",z,ans[n]);
    }
    return 0;
}

