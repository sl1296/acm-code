
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[110][110];
int dp[110][110];
int main(){
  //  system("chcp 936");
    int n;
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}

