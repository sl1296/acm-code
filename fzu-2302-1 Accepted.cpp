
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 210
struct Point{
    ll x,y;
    Point(){}
    Point(ll x,ll y):x(x),y(y){}
}q[N];
ll dp[N][N];
ll cross(Point &p0,Point &p1,Point &p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int n,m;
int a[N*2],sum[N*2];
inline ll sqr(int x)
{
    return (ll)x*x;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=n+1;i<=n*2;++i) a[i]=a[i-n];
        for(int i=1;i<=n*2;++i) sum[i]=sum[i-1]+a[i];
        ll ans=1e9;
        for(int l=0;l<n;++l)
        {
            for(int i=1;i<=n;++i) dp[i][0]=1e9;
            for(int j=1;j<=m;++j)
            {
                dp[0][j]=0;
                q[0]=Point(0,0);
                int s=0,t=0;
                ll k,z;
                Point p;
                for(int i=1;i<=n;++i)
                {
                    k=2LL*(sum[i+l]-sum[l]);z=sqr(sum[i+l]-sum[l]);
                    while(s<t&&q[s].y-k*q[s].x+z>=q[s+1].y-k*q[s+1].x+z) ++s;
                    dp[i][j]=q[s].y-k*q[s].x+z;
                    p=Point(sum[i+l]-sum[l],dp[i][j-1]+sqr(sum[i+l]-sum[l]));
                    while(s<t&&cross(q[t-1],q[t],p)<=0) --t;
                    q[++t]=p;
                }
            }
            ans=min(ans,dp[n][m]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

