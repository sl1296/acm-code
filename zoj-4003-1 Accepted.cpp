
#include <bits/stdc++.h>
using namespace std;
#define N 1010
typedef long long ll;
ll a[N],b[N],c[N];
int n,p;
ll V;
inline ll Pow(ll x)
{
    ll ans=x;
    for(int i=1;i<p;++i)
        ans*=x;
    return ans;
}
ll calc(ll c[],int m)
{
    ll cnt=0,sum=0;
    int l=1;
    for(int r=1;r<=m;++r)
    {
        sum+=c[r];
        while(l<=r&&sum>V) sum-=c[l++];
        if(l<=r) cnt+=r-l+1;
    }
    return cnt;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%lld%d",&n,&V,&p);
        for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
        for(int i=1;i<=n;++i) scanf("%lld",&b[i]);
        ll ans=0;
        for(int k=0;k<n;++k)
        {
            int m=0;
            for(int i=1;i<=n&&i+k<=n;++i)
                c[++m]=Pow(abs(a[i]-b[i+k]));
            ans+=calc(c,m);
        }
        for(int k=1;k<n;++k)
        {
            int m=0;
            for(int i=1;i<=n&&i+k<=n;++i)
                c[++m]=Pow(abs(a[i+k]-b[i]));
            ans+=calc(c,m);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

