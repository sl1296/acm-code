
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define N 100010
ll fac[N],fac_inv[N],inv[N],P2[N];
void init()
{
    P2[0]=1;
    for(int i=1;i<N;++i) P2[i]=P2[i-1]*2%mod;
    inv[1] = 1;
    for(int i=2;i<N;i++)
    {
        if(i>=mod) break;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
//    for(int i=0;i<10;++i) printf("%lld ",inv[i]);
//    printf("\n");
    fac[0]=1;
    for(int i=1;i<N;++i)
        fac[i]=fac[i-1]*i%mod;
//    for(int i=0;i<10;++i) printf("%lld ",fac[i]);
//    printf("\n");
    fac_inv[0]=1;
    for(int i=1;i<N;++i)
        fac_inv[i]=fac_inv[i-1]*inv[i]%mod;
//    for(int i=0;i<10;++i) printf("%lld ",fac_inv[i]);
//    printf("\n");
}
inline ll C(int n,int m)
{
//    printf("%d %d %lld !\n",n,m,fac[n]*fac_inv[m]%mod*fac_inv[n-m]%mod);
    return fac[n]*fac_inv[m]%mod*fac_inv[n-m]%mod;
}
ll sum[100][100];
inline void update(ll &x,ll y)
{
    x+=y;
    while(x>=mod) x-=mod;
}
int main()
{
    init();
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=0;
        if(m>(n+1)/2)
        {
            for(int i=m+1;i<=n;++i)
                update(ans,C(n,i));
            ans=P2[n]-ans;
            update(ans,mod);
        }
        else
        {
            for(int i=0;i<=m;++i)
//                ans=(ans+C(n,i))%mod;
                update(ans,C(n,i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
6 8 3 4

2 3 1 1

10 7 3 4
*/


