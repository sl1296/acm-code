
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 50010
#define M 1250010
typedef long long ll;
const ll mod=1e9+7;
struct rec{
    int x,y,t,k,w,p,be;
}a[M],tmp[M];
ll c1[N],c2[N],ans[N];
int ord[N],v[N];
int n,m;
inline void Add(ll &x,ll y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
void add(int x,ll w,ll c[])
{
    for(;x<=n;x+=x&-x) Add(c[x],w);
}
ll getsum(int x,ll c[])
{
    ll ans=0;
    for(;x;x-=x&-x) Add(ans,c[x]);
    return ans;
}
bool cmp(const rec &a,const rec &b)
{
    return a.y<b.y||a.y==b.y&&a.k<b.k;
}
inline ll posive(ll x)
{
    if(x<0) x+=mod;
    return x;
}
void solve(int l,int r)
{
    if(l==r) return;
    int mid=l+r>>1;
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid&&a[i].k==1)
        {
            add(a[i].x,a[i].w,c1);
            add(a[i].x,a[i].p,c2);
        }
        else if(a[i].t>mid&&a[i].k==2)
        {
            Add(ans[a[i].be],posive(getsum(a[i].x,c1)*a[i].w));
            Add(ans[a[i].be],posive(getsum(a[i].x,c2)*a[i].w)*a[i].p%mod);
        }
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid&&a[i].k==1)
        {
            add(a[i].x,posive(-a[i].w),c1);
            add(a[i].x,posive(-a[i].p),c2);
        }
    int ll=l,rr=mid+1;
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid) tmp[ll++]=a[i];
        else tmp[rr++]=a[i];
    for(int i=l;i<=r;++i) a[i]=tmp[i];
    solve(l,mid);solve(mid+1,r);
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        int tot=0,x,y;
        for(int i=0;i<=n;++i) ans[i]=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&x,&y);
            ord[i]=x;v[i]=y;
            a[++tot].x=i;a[tot].y=ord[i];a[tot].t=tot;a[tot].k=1;a[tot].w=v[i];a[tot].p=1;
        }
        for(int i=n;i>0;--i)
        {
            Add(ans[0],getsum(ord[i]-1,c1));
            Add(ans[0],getsum(ord[i]-1,c2)*v[i]%mod);
            add(ord[i],v[i],c1);
            add(ord[i],1,c2);
        }
        for(int i=1;i<=m;++i)
        {
            ans[i]=0;
            scanf("%d%d",&x,&y);
            a[++tot].x=x;a[tot].y=ord[x];a[tot].t=tot;a[tot].k=1;a[tot].w=-v[x];a[tot].p=-1;
            a[++tot].x=n;a[tot].y=ord[x]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x;a[tot].y=ord[x]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x-1;a[tot].y=n;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x-1;a[tot].y=ord[x];a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[x];

            a[++tot].x=y;a[tot].y=ord[y];a[tot].t=tot;a[tot].k=1;a[tot].w=-v[y];a[tot].p=-1;
            a[++tot].x=n;a[tot].y=ord[y]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y;a[tot].y=ord[y]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y-1;a[tot].y=n;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y-1;a[tot].y=ord[y];a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[y];

            swap(ord[x],ord[y]);swap(v[x],v[y]);

            a[++tot].x=x;a[tot].y=ord[x];a[tot].t=tot;a[tot].k=1;a[tot].w=v[x];a[tot].p=1;
            a[++tot].x=n;a[tot].y=ord[x]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x;a[tot].y=ord[x]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x-1;a[tot].y=n;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[x];
            a[++tot].x=x-1;a[tot].y=ord[x];a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[x];

            a[++tot].x=y;a[tot].y=ord[y];a[tot].t=tot;a[tot].k=1;a[tot].w=v[y];a[tot].p=1;
            a[++tot].x=n;a[tot].y=ord[y]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y;a[tot].y=ord[y]-1;a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y-1;a[tot].y=n;a[tot].t=tot;a[tot].k=2;a[tot].w=1;a[tot].be=i;a[tot].p=v[y];
            a[++tot].x=y-1;a[tot].y=ord[y];a[tot].t=tot;a[tot].k=2;a[tot].w=-1;a[tot].be=i;a[tot].p=v[y];

        }
        for(int i=1;i<=n;++i) c1[i]=c2[i]=0;
        sort(a+1,a+tot+1,cmp);
        solve(1,tot);
        for(int i=1;i<=m;++i) Add(ans[i],ans[i-1]);
        for(int i=1;i<=m;++i) printf("%I64d\n",ans[i]);
    }
    return 0;
}
/*
2
5 4
5 5
2 2
3 3
4 4
1 1
1 5
2 4
5 3
1 3
2 2
2 2
1 1
1 2
1 2
*/

