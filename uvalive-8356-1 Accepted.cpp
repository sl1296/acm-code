
#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define M 2000010
#define lx x<<1
#define rx x<<1|1
#define lson lx,s,mid
#define rson rx,mid+1,t
struct rec{
    int l,r,h;
    rec(){}
    rec(int l,int r,int h):l(l),r(r),h(h){}
}a[M];
int seg[N*6],lazy[N*6];
int n,m;
void build(int x,int s,int t)
{
    seg[x]=lazy[x]=0;
    if(s==t) return;
    int mid=s+t>>1;
    build(lson);build(rson);
}
void pushdown(int x,int s,int t)
{
    if(lazy[x])
    {
        if(s!=t)
        {
            int mid=s+t>>1;
            seg[lx]=mid-s+1-seg[lx];lazy[lx]^=1;
            seg[rx]=t-mid-seg[rx];lazy[rx]^=1;
        }
        lazy[x]=0;
    }
}
void update(int x,int s,int t,int l,int r)
{
    if(l<=s&&t<=r)
    {
        seg[x]=t-s+1-seg[x];
        lazy[x]^=1;
        return;
    }
    pushdown(x,s,t);
    int mid=s+t>>1;
    if(l<=mid) update(lson,l,r);
    if(mid<r) update(rson,l,r);
    seg[x]=seg[lx]+seg[rx];
}
bool cmp(rec &a,rec &b)
{
    return a.h<b.h;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        build(1,1,n);
        int x1,y1,x2,y2,z=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            if(x1>x2||y1>y2) continue;
            a[++z]=rec(x1,x2,y1-1);
            a[++z]=rec(x1,x2,y2);
        }
        sort(a+1,a+z+1,cmp);
        int ans=0;
        for(int i=1;i<z;++i)
        {
            update(1,1,n,a[i].l,a[i].r);
            ans+=seg[1]*(a[i+1].h-a[i].h);
            // printf("%d %d %d ?\n",seg[1],a[i].h,a[i+1].h);
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
5 2
2 4 1 3
1 5 3 5
5 2
1 5 1 2
1 5 3 5
*/

