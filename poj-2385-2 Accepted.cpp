
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1010];
int dp[1010][35];
int main(){
    int t,w;
    while(~scanf("%d%d",&t,&w)){
        for(int i=0;i<t;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        if(a[0]==1)dp[0][0]++;else dp[0][1]++;
        for(int i=1;i<t;i++){
            for(int j=0;j<=w;j++){
                if((a[i]==1&&j%2==0)||(a[i]==2&&j%2==1)){
                    dp[i][j]=dp[i-1][j]+1;
                    if(j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                }else{
                    dp[i][j]=dp[i-1][j];
                    if(j)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=w;i++)ans=max(ans,dp[t-1][i]);
        printf("%d\n",ans);
    }
    return 0;
}

