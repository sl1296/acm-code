
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
struct rec{
    int w,id;
}a[N];
int fa[N];
int n;
bool cmp(rec &a,rec &b)
{
    return a.w<b.w;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i].w);
            a[i].id=i;
        }
        ll ans=(int)sqrt(abs(a[1].w-a[n].w));
//        sort(a+1,a+n+1,cmp);
//        for(int i=1;i<=n;++i)
//            fa[a[i].id]=i;
//        int d=(fa[n]-fa[1])/abs(fa[n]-fa[1]);
//        ll tmp=0;
//        for(int i=fa[1]+d;i!=fa[n];i+=d)
//            tmp+=(int)(sqrt(abs(a[i].w-a[i-d].w)));
//
//        ans=min(ans,tmp);
        printf("%lld\n",ans);
    }
    return 0;
}

