
#include <bits/stdc++.h>
using namespace std;
#define N 200010
struct rec{
    int lson,rson,w;
    void init(int z)
    {
        w=z;lson=rson=0;
    }
}seg[N*22];
vector<int> g[N];
int root[N];
int ca,n,m,cnt;
void build(int &x,int s,int t)
{
    seg[x=++cnt].init(0);
    if(s==t) return;
    int mid=s+t>>1;
    build(seg[x].lson,s,mid);
    build(seg[x].rson,mid+1,t);
}
void update(int &x,int rot,int s,int t,int id)
{
    if(!x) seg[x=++cnt].init(seg[rot].w);
    seg[x].w++;
    if(s==t) return;
    int mid=s+t>>1;
    if(id<=mid)
    {
        update(seg[x].lson,seg[rot].lson,s,mid,id);
        seg[x].rson=seg[rot].rson;
    }
    else
    {
        seg[x].lson=seg[rot].lson;
        update(seg[x].rson,seg[rot].rson,mid+1,t,id);
    }
}
int query(int x,int rot,int s,int t,int l,int r)
{
    if(l<=s&&t<=r) return seg[x].w-seg[rot].w;
    int mid=s+t>>1,ans=0;
    if(l<=mid) ans+=query(seg[x].lson,seg[rot].lson,s,mid,l,r);
    if(mid<r) ans+=query(seg[x].rson,seg[rot].rson,mid+1,t,l,r);
    return ans;
}
int main()
{
    int x,y;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
        }
        for(int i=0;i<=n;++i) root[i]=0;
        cnt=0;
        build(root[0],1,n);
        for(int i=1;i<=n;++i)
        {
            int last=root[i-1];
            for(auto j:g[i])
            {
                root[i]=0;
                update(root[i],last,1,n,j);
                last=root[i];
            }
            root[i]=last;
//            printf("%d %d ?\n",i,query(root[i],root[0],1,n,1,2));
        }
        while(m--)
        {
            scanf("%d%d",&x,&y);
            printf("%d\n",y-x+1-query(root[y],root[x-1],1,n,x,y));
        }
    }
    return 0;
}

