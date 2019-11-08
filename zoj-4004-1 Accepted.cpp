
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
typedef long long ll;
ll a[N];
int n,m,ca;
int main()
{
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        ll ans=0;
        for(int i=1;i<=m;++i)
            ans+=a[i]*a[2*m-i+1];
        printf("%lld\n",ans);
    }
    return 0;
}

