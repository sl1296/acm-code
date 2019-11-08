
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll mod=998244353;
ll a[N];
void init()
{
    a[1]=0;a[2]=0;a[3]=1;
    for(int i=4;i<N;++i)
    {
        a[i]=(i-3)*a[i-1]%mod+(i-2)*((2*a[i-2]+a[i-3])%mod)%mod;
    }
}
int main()
{
    init();
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",a[n]);
    }
    return 0;
}

