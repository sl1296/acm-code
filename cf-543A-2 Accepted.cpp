
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[510];
int dp[510][510];
int main(){
    int n,m,b,mod;
    while(~scanf("%d%d%d%d",&n,&m,&b,&mod)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=a[i];k<=b;k++){
                    dp[j][k]=(dp[j][k]+dp[j-1][k-a[i]])%mod;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=b;i++){
            ans=(ans+dp[m][i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}

