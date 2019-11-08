
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
const ll mod=1e9+7;
ll fac[N],inv[N],inv_fac[N];
int a[N],b[N];
void init()
{
    inv[1] = 1; 
    for(int i=2;i<N;i++) 
    { 
        if(i >= mod) break; 
        inv[i] = (mod - mod / i) * inv[mod % i] % mod; 
    }
    fac[0]=1;
    for(int i=1;i<N;++i) fac[i]=fac[i-1]*i%mod;
    inv_fac[0]=1;
    for(int i=1;i<N;++i) inv_fac[i]=inv_fac[i-1]*inv[i]%mod; 
}
ll C(int n,int m)
{
    return fac[n]*inv_fac[m]%mod*inv_fac[n-m]%mod;
}
int main()
{
    init();
    int ca,n,m;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<n;++i)
            scanf("%d%d",&a[i],&b[i]);
        printf("%lld\n",C(n-1,m-1)*fac[m]%mod);
    }
    return 0;
}

