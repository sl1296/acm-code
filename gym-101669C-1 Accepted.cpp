
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
#define lson node<<1,s,mid
#define rson node<<1|1,mid+1,t
#define lnode node<<1
#define rnode node<<1|1
int son[N],sz[N],top[N],ti[N],dep[N],fa[N],dfn[N];
int c[N],a[N],b[N],d[N],ru[N*6],seg[N*6],to[N],sta[N*6];
int n,m,cnt,z;
bool vis[N];
vector<int>g[N],gg[N*6];
vector<int> vec[N];
void dfs1(int x,int depth,int pa)
{
    dep[x]=depth;sz[x]=1;son[x]=0;fa[x]=pa;
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(y==pa) continue;
        dfs1(y,depth+1,x);
        sz[x]+=sz[y];
        if(sz[y]>sz[son[x]]) son[x]=y;
    }
}
void dfs2(int x,int pa)
{
    ti[x]=++cnt;dfn[cnt]=x;top[x]=pa;
    if(son[x]!=0) dfs2(son[x],top[x]);
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(y!=son[x]&&y!=fa[x])
            dfs2(y,y);
    }
}
int lca(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    return x;
}
int u,v;
bool has_c(int co,int s,int t)
{
    int l=lower_bound(vec[co].begin(),vec[co].end(),s)-vec[co].begin()-1;
    int r=upper_bound(vec[co].begin(),vec[co].end(),t)-vec[co].begin();
    return r-l>1;
}
void update(int node,int s,int t,int l,int r)
{
    if(l<=s&&t<=r&&!has_c(c[u],s,t))
    {
        gg[c[u]+z].push_back(node);
        ru[node]++;
        return;
    }
    if(s==t) return;
    int mid=s+t>>1;
    if(l<=mid) update(lson,l,r);
    if(mid<r) update(rson,l,r);
}
void addedge(int x,int y)
{
    u=x;v=y;
    int l,r;
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]]) swap(x,y);
        l=ti[top[x]];r=ti[x];
        update(1,1,n,l,r);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y]) swap(x,y);
    l=ti[x];r=ti[y];
    update(1,1,n,l,r);
}
void dfs3(int x,int pa)
{
    if(d[c[x]]==0) d[c[x]]=x;
    if(a[c[x]]==0) a[c[x]]=x;
    else
    {
        int L=lca(a[c[x]],x);
        if(L==a[c[x]]) a[c[x]]=x;
        else
        {
            b[c[x]]=a[c[x]];
            a[c[x]]=x;
        }
    }
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(y!=pa) dfs3(y,x);
    }
}
void build(int node,int s,int t)
{
    z=max(z,node);
    if(s==t)
    {
        to[s]=node;seg[node]=s;return;
    }
    int mid=s+t>>1;
    build(lson);build(rson);
}
void doing(int node,int s,int t)
{
    if(s==t) return;
    // printf("%d !!\n",node);
    if(ru[node])
    {
        gg[node].push_back(lnode);++ru[lnode];
        gg[node].push_back(rnode);++ru[rnode];
    }
    int mid=s+t>>1;
    doing(lson);doing(rson);
}
int main()
{
    // freopen("data.in","r",stdin);
    // freopen("data.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&c[i]);
    int x,y;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cnt=0;
    dfs1(1,1,1);
    dfs2(1,1);
    dfs3(1,1);
    build(1,1,n);
    // for(int i=1;i<=n;++i) printf("%d ",ti[i]);printf("\n");
    // for(int i=1;i<=n;++i) printf("%d ",dfn[i]);printf("\n");
    // for(int i=1;i<=n;++i) printf("%d ",to[i]);printf("\n");
    for(int i=1;i<=n;++i) vec[c[dfn[i]]].push_back(i);
    for(int i=1;i<=m;++i)
        if(b[i]==0) b[i]=d[i];
    for(int i=1;i<=m;++i)
        if(d[i]) addedge(a[i],b[i]);
    // for(int i=1;i<=z+m;++i)
    // {
    //     printf("%d %d : ",i,ru[i]);
    //     for(auto x:gg[i]) printf("%d ",x);
    //     printf("\n");
    // }
    doing(1,1,n);
    
    for(int i=1;i<=n;++i)
    {
        gg[to[ti[i]]].push_back(c[i]+z);
        ++ru[c[i]+z];
    }
    // for(int i=1;i<=z+m;++i)
    // {
    //     printf("%d : ",i);
    //     for(auto x:gg[i]) printf("%d ",x);
    //     printf("\n");
    // }
    int t=0;
    for(int i=1;i<=z+m;++i)
        if(ru[i]==0) sta[++t]=i;
    while(t)
    {
        x=sta[t--];
        if(x>z)
        {
            int co=x-z;
            if(d[co]) printf("%d %d %d\n",co,a[co],b[co]);
            else printf("%d 1 1\n",co);
        }
        for(int y:gg[x])
        {
            --ru[y];
            if(ru[y]==0) sta[++t]=y;
        }
    }
    return 0;
}
/*
7 2
2 2 2 2 2 1 1
1 2
2 3
3 4
4 5
4 6
3 7
*/

