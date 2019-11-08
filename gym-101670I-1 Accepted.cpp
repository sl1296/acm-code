
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int a[N],b[N],c[N];
int n;
ll ans;
void calc(int c[])
{
    sort(c+1,c+n+1);
    int j=1;
    for(int i=2;i<=n;++i)
        if(c[i]!=c[j])
        {
            if(i-j>=2) ans+=(ll)(i-j)*(i-j-1);
            j=i;
        }
    if(n+1-j>=2) ans+=(ll)(n+1-j)*(n-j);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
            scanf("%d%d",&a[i],&b[i]);
        ans=0;
        for(int i=1;i<=n;++i)
            c[i]=a[i]+b[i];
        calc(c);
        for(int i=1;i<=n;++i)
            c[i]=-a[i]+b[i];
        calc(c);
        ll tot=(ll)n*n;
        printf("%.8f\n",(double)ans/tot);
    }
    return 0;
}

