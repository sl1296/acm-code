
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define N 100010
ll a[N];
int n;
int main()
{
    scanf("%d",&n);
    ll ans=0,tmp=1;
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&a[i]);
        ans=(ans+a[i]*(a[i]+1)/2)%mod;
        tmp=tmp*(a[i]+1)%mod;
    }
    ans=(ans+tmp)%mod;
    printf("%lld\n",ans);
    return 0;
}

