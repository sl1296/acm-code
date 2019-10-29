
#include <bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
int n,k;
int a[N];
int main()
{
    scanf("%d%d",&n,&k);
    ll ans=0;
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    int last=a[1];
    for(int i=2;i<=n;++i)
    {
        if(last%k==0) ans+=last/k;
        else
        {
            ans+=last/k+1;
            int tmp=last%k;
            a[i]=max(0,a[i]-(k-tmp));
        }
        last=a[i];
    }
    ans+=last/k;
    if(last%k) ++ans;
    printf("%I64d\n",ans);
    return 0;
}

