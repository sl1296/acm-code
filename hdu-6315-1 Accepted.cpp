
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define lx x<<1
#define rx x<<1|1
#define lson lx,s,mid
#define rson rx,mid+1,t
typedef long long ll;
int seg[N*4],lazy[N*4];
int a[N],b[N],c[N];
int n,m;
void build(int x,int s,int t)
{
    lazy[x]=0;
    if(s==t)
    {
        seg[x]=b[s];c[s]=0;
        return;
    }
    int mid=s+t>>1;
    build(lson);build(rson);
    seg[x]=min(seg[lx],seg[rx]);
}
void pushdown(int x,int s,int t)
{
    if(lazy[x])
    {
        if(s!=t)
        {
            seg[lx]-=lazy[x];lazy[lx]+=lazy[x];
            seg[rx]-=lazy[x];lazy[rx]+=lazy[x];
        }
        lazy[x]=0;
    }
}
void updata(int x,int s,int t,int l,int r)
{
//    printf("%d %d %d %d ?\n",s,t,l,r);
    if(l<=s&&t<=r)
    {
        --seg[x];++lazy[x];
        return;
    }
    pushdown(x,s,t);
    int mid=s+t>>1;
    if(l<=mid) updata(lson,l,r);
    if(mid<r) updata(rson,l,r);
    seg[x]=min(seg[lx],seg[rx]);
}
int query(int x,int s,int t)
{
//    printf("%d %d %d !\n",s,t,seg[x]);
    if(seg[x]) return 0;
    if(s==t) return s;
    pushdown(x,s,t);
    int mid=s+t>>1;
//    printf("%d %d %d %d ???\n",s,t,seg[lx],seg[rx]);
    if(seg[lx]==0) return query(lson);
    if(seg[rx]==0) return query(rson);
}
void set0(int x,int s,int t,int id)
{
//    printf("%d %d %d ##\n",s,t,id);
    if(s==t)
    {
        seg[x]=b[s];lazy[x]=0;
        return;
    }
    pushdown(x,s,t);
    int mid=s+t>>1;
    if(id<=mid) set0(lson,id);
    else set0(rson,id);
    seg[x]=min(seg[lx],seg[rx]);
}
void add(int x,int z)
{
    for(;x<=n;x+=x&-x) c[x]+=z;
}
int sum(int x)
{
    int ans=0;
    for(;x;x-=x&-x) ans+=c[x];
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i) scanf("%d",&b[i]);
        build(1,1,n);
        char st[10];
        int l,r,x;
        for(int i=1;i<=m;++i)
        {
            scanf("%s",st);
            scanf("%d%d",&l,&r);
            if(st[0]=='a')
            {
                updata(1,1,n,l,r);
                while(true)
                {
                    x=query(1,1,n);
                    if(x==0) break;
//                    printf("%d ##\n",x);
                    set0(1,1,n,x);
                    add(x,1);
                }
            }
            else
            {
                printf("%d\n",sum(r)-sum(l-1));
            }
        }
    }
    return 0;
}

