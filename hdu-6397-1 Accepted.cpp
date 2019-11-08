
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
typedef long long ll;
const ll mod=998244353;
ll fac[N],fac_inv[N],inv[N];
void init()
{
    inv[1] = 1;
    for(int i=2;i<N;i++)
    {
        if(i >= mod) break;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    fac[0]=1;
    for(int i=1;i<N;++i)
        fac[i]=fac[i-1]*i%mod;
    fac_inv[0]=1;
    for(int i=1;i<N;++i)
        fac_inv[i]=fac_inv[i-1]*inv[i]%mod;
}
ll C(int n,int m)
{
    if(n<m) return 0;
//    if(n<m) printf("%d %d ?\n",n,m);
//    assert(n>=m);
//    printf("%d %d ?\n",n,m);
    ll tmp=fac[n]*fac_inv[m]%mod*fac_inv[n-m]%mod;
//    printf("%lld !\n",tmp);
    return tmp;
}
int main()
{
    init();
//    printf("%lld ?\n",C(6,3));
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        ll ans=0,tmp;
        int z=k/n;
        for(int i=0;i<=z;++i)
        {
//            printf("%d %d @@\n",m+k-1-n*i,n-1);
            tmp=C(m,i)*C(m+k-1-n*i,m-1)%mod;
            if(i&1) tmp=mod-tmp;
            ans=(ans+tmp)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
5
2 3 3
2 3 4
3 3 3
128 3 340
128 3 111111
*/

