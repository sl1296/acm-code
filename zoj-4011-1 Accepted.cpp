
#include <bits/stdc++.h>
using namespace std;
#define N 2010
typedef long long ll;
const ll mod=1e9+7;
int ca,n,m;
ll dp[N][N];
vector<int> g[N];
void Add(ll &x,ll y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
int main()
{
    for(int i=1;i<N;++i)
        for(int j=1;j<=i;++j)
            if(i%j==0) g[i].push_back(j);
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;++i)
            dp[1][i]=1;
        for(int i=2;i<=m;++i)
            for(int j=1;j<=n;++j)
                for(int k:g[j])
                    Add(dp[i][j],dp[i-1][k]);
        ll ans=0;
        for(int i=1;i<=n;++i)
            Add(ans,dp[m][i]);
        printf("%lld\n",ans);
    }
    return 0;
}

