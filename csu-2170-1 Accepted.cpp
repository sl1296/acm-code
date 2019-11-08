
#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define M 100010
struct rec{
    int x,y,t,k,w,be;
}a[M*4],tmp[M*4];
int c[N],ans[M];
int n,m;
void add(int x,int w)
{
    for(;x<=n;x+=x&-x) c[x]+=w;
}
int getsum(int x)
{
    int ans=0;
    for(;x;x-=x&-x) ans+=c[x];
    return ans;
}
bool cmp(const rec &a,const rec &b)
{
    return a.y<b.y||a.y==b.y&&a.k<b.k;
}
void solve(int l,int r)
{
    if(l==r) return;
//    printf("%d %d ----\n",l,r);
//    for(int i=l;i<=r;++i)
//        printf("%d %d %d %d %d %d\n",a[i].x,a[i].y,a[i].t,a[i].k,a[i].w,a[i].be);
    int mid=l+r>>1;
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid&&a[i].k==1) add(a[i].x,a[i].w);
        else if(a[i].t>mid&&a[i].k==2) ans[a[i].be]+=getsum(a[i].x)*a[i].w;
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid&&a[i].k==1) add(a[i].x,-a[i].w);
    int ll=l,rr=mid+1;
    for(int i=l;i<=r;++i)
        if(a[i].t<=mid) tmp[ll++]=a[i];
        else tmp[rr++]=a[i];
    for(int i=l;i<=r;++i) a[i]=tmp[i];
    solve(l,mid);solve(mid+1,r);
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int tot=0,k,x,y,z=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&k,&x,&y);
            if(k==1)
            {
                a[++tot].x=x;a[tot].y=y;a[tot].t=tot;a[tot].k=k;a[tot].w=1;
            }
            else
            {
                a[++tot].x=x;a[tot].y=n;a[tot].t=tot;a[tot].k=k;a[tot].w=1;a[tot].be=++z;
                a[++tot].x=x;a[tot].y=y-1;a[tot].t=tot;a[tot].k=k;a[tot].w=-1;a[tot].be=z;
            }
        }
        for(int i=1;i<=z;++i) ans[i]=0;
        sort(a+1,a+tot+1,cmp);
        solve(1,tot);
        for(int i=1;i<=z;++i) printf("%d\n",ans[i]);
    }
    return 0;
}

