
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll mod=1e9+7;
char a[N],b[N];
int h[26];
vector<ll> dp[2];
vector<ll> sum;
void Add(ll &x,ll y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<2;++i)
        dp[i]=vector<ll>(m+10);
    sum=vector<ll>(m+10);
    for(int i=0;i<26;++i)
    {
        scanf("%d",&h[i]);
        if(h[i]<0) h[i]=0;
        h[i]=min(h[i],m);
    }
    scanf("%s",a+1);
    scanf("%s",b+1);
    for(int i=1;i<=n;++i) a[i]-='A';
    for(int i=1;i<=m;++i) b[i]-='A';
    for(int i=n;i>0;--i)
    {
        for(int j=1;j<=m+1;++j) dp[i&1][j]=0;
        sum[m+1]=0;
        for(int j=m;j>0;--j) sum[j]=(sum[j+1]+dp[(i+1)&1][j])%mod;
        for(int j=m;j>0;--j)
        {
            if(a[i]==b[j])
            {
                if(i==n) dp[i&1][j]=1;
                else
                {
                    int k=min(m+1,j+h[b[j]]+1);
                    Add(dp[i&1][j],sum[k]);
                }
            }
//            printf("%lld ",dp[i][j]);
        }
//        printf("\n");
    }
    ll ans=0;
    for(int j=1;j<=m;++j)
        if(a[1]==b[j])
            Add(ans,dp[1][j]);
    printf("%I64d\n",ans);
    return 0;
}
/*
3 10
1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
ABB
ABBBBABBBB
*/

