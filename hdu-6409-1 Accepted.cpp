
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int n;
int a[N];
vector<int> g[N];
bool cmp(int x,int y)
{
    return a[x]<a[y];
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) g[i].clear();
        int x;
        for(int i=2;i<=n;++i)
        {
            scanf("%d",&x);
            g[x].push_back(i);
        }
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)
            sort(g[i].begin(),g[i].end(),cmp);
        ll mi=0,mx=0;
        for(int i=1;i<=n;++i)
            if(g[i].size())
            {
                x=g[i][0];
                if(a[x]<0) mi+=a[x];
                x=g[i][g[i].size()-1];
                if(a[x]>0) mx+=a[x];
            }
        if(a[1]>0) mx+=a[1];
        else if(a[1]<0) mi+=a[1];
        ll ans_mi=mi,ans_mx=mx;
        for(int i=1;i<=n;++i)
            if(g[i].size()>1)
            {
                x=g[i][1];
                if(a[x]<0) ans_mi=min(ans_mi,mi+a[x]);
                x=g[i][g[i].size()-2];
                if(a[x]>0) ans_mx=max(ans_mx,mx+a[x]);
            }
        printf("%lld %lld\n",ans_mx,ans_mi);
    }
    return 0;
}

