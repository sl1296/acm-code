
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
int a[2010],b[2010];
long long dp[2][2010][2010];
int ma2[2010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b+1,b+n+1);
        int cnt=1;
        map<int,int> ma;
        b[0]=0;
        for(int i=1;i<=n;i++){
            ma[b[i]]=cnt;
            ma2[cnt]=b[i];
            cnt++;
            while(i+1<=n&&b[i]==b[i+1])i++;
        }
        for(int i=1;i<=n;i++)a[i]=ma[a[i]];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<cnt;j++){
                dp[0][i][j]=dp[0][i-1][j]+abs(ma2[a[i]]-ma2[j]);
                dp[1][i][j]=dp[1][i-1][j]+abs(ma2[a[i]]-ma2[j]);
            }
            for(int j=1;j<cnt;j++){
                dp[0][i][j]=min(dp[0][i][j],dp[0][i][j-1]);
            }
            for(int j=cnt-2;j>=0;j--){
                dp[1][i][j]=min(dp[1][i][j],dp[1][i][j+1]);
            }
        }
        long long ans=1LL<<60;
        for(int i=0;i<cnt;i++){
            ans=min(ans,dp[0][n][i]);
            ans=min(ans,dp[1][n][i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

