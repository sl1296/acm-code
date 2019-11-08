
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int a[1100000];
int sum[1100000];
ll dp[30][30];
ll c[30][30];
ll jc[30]={1};
int binc[1100000];
int main(){
    dp[0][1]=1;
    for(int i=0;i<21;i++)dp[i][0]=1;
    for(int i=1;i<21;i++){
        for(int j=1;j<i;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        dp[i][i+1]=dp[i][i]=dp[i][i-1];
    }
    for(int i=0;i<21;i++)c[i][0]=1;
    for(int i=1;i<21;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j-1]+c[i-1][j];
        }
    }
    for(int i=1;i<21;i++)jc[i]=jc[i-1]*i;
    for(int i=1;i<(1<<20);i++)binc[i]=binc[i-(i&-i)]+1;
    int t;
    scanf("%d",&t);
    while(t--){
        int p,n,m;
        scanf("%d%d%d",&p,&n,&m);
        for(int i=0;i<m;i++)scanf("%d",&a[1<<i]);
        for(int i=1;i<(1<<m);i++)sum[i]=sum[i-(i&-i)]+a[i&-i];
        ll ans=0;
        for(int i=0;i<(1<<m);i++){
            if(sum[i]>=p&&binc[i]<=n+1){
                if(binc[i]==m&&binc[i]<n+1)ans+=dp[n][m]*jc[n]*jc[m];
                else ans+=c[n][binc[i]-1]*dp[binc[i]-1][binc[i]]*jc[binc[i]]*jc[binc[i]-1]*jc[n+m-2*binc[i]+1];

            }
        }
        ll all=jc[n+m];
        ll d=__gcd(all,ans);
        printf("%lld/%lld\n",ans/d,all/d);
    }
    return 0;
}

