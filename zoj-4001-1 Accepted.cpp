
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 400010
typedef long long ll;
const ll inf=1e16;
struct rec{
    int x;
    ll w;
    rec(){}
    rec(int x,ll w):x(x),w(w){}
    bool operator<(const rec &a)const
    {
        return w>a.w;
    }
};
int head[N],to[M],w[M],pre[M],a[N],bot[N],fa[N][17],dep[N];
int n,m,e;
ll d[N],mx[N][17];
vector<rec> g[N];
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
priority_queue<rec> que;
void dij(int s)
{
    d[s]=0;que.push(rec(s,0));bot[s]=s;
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        int x=p.x;
        if(p.w>d[x]) continue;
        if(a[x]&&x!=s)
        {
            g[x].push_back(rec(bot[x],d[x]));
            g[bot[x]].push_back(rec(x,d[x]));
            d[x]=0;bot[x]=x;
        }
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            ll cost=d[x]+w[i];
            if(cost<d[y])
            {
                d[y]=cost;bot[y]=bot[x];
                que.push(rec(y,cost));
            }
        }
    }
}
void print_tree()
{
    for(int i=1;i<=n;++i)
    {
        printf("%d -----\n",i);
        for(auto edge:g[i])
            printf("%d %d %lld\n",i,edge.x,edge.w);
    }
}
void dfs(int x,int p,ll val)
{
    fa[x][0]=p;mx[x][0]=val;
    for(int i=1;i<17;++i)
    {
        fa[x][i]=fa[fa[x][i-1]][i-1];
        mx[x][i]=max(mx[x][i-1],mx[fa[x][i-1]][i-1]);
    }
    for(auto e:g[x])
    {
        if(e.x==p) continue;
        dep[e.x]=dep[x]+1;
        dfs(e.x,x,e.w);
    }
}
ll LCA(int x,int y)
{
    ll ans=0;
    if(dep[x]>dep[y]) swap(x,y);
    int d=dep[y]-dep[x];
    for(int i=0;i<17;++i)
        if((d>>i)&1)
        {
            ans=max(ans,mx[y][i]);
            y=fa[y][i];
        }
    if(x==y) return ans;
    for(int i=16;i>=0;--i)
        if(fa[x][i]!=fa[y][i])
        {
            ans=max(ans,max(mx[x][i],mx[y][i]));
            x=fa[x][i];y=fa[y][i];
        }
    ans=max(ans,max(mx[x][0],mx[y][0]));
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=n;++i) head[i]=-1;
    e=0;
    int x,y,z;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);addedge(y,x,z);
    }
    for(int i=1;i<=n;++i) d[i]=inf;
    for(int i=1;i<=n;++i)
        if(a[i]&&d[i]==inf) dij(i);
//    print_tree();
    for(int i=1;i<=n;++i)
        if(a[i]&&!fa[i][0])
            dfs(i,i,0);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&x,&y);
        printf("%lld\n",LCA(x,y));
    }
    return 0;
}
/*
8 9
1 0 1 0 1 1 1 1
1 2 2
1 4 1
2 3 2
4 5 4
3 6 10
3 5 2
5 6 5
7 8 5
7 8 10
3
1 6
1 5
7 8
*/

