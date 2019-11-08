
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1000000000000000000LL;
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
int head[N],to[N*2],pre[N*2],c[N*2],w[N*2];
bool vis[N*2];
ll d[N*2];
int n,m,e;
void addedge(int x,int y,int z1,int z2)
{
    to[e]=y;c[e]=z1;w[e]=z2;pre[e]=head[x];head[x]=e++;
}
ll dijkstra()
{
    priority_queue<rec> que;
    for(int i=0;i<e;++i)
    {
        vis[i]=false;d[i]=inf;
    }
    int x,y,u,v;
    for(int i=head[1];i!=-1;i=pre[i])
    {
        d[i]=w[i];
        que.push(rec(i,d[i]));
    }
    while(!que.empty())
    {
        rec p=que.top();que.pop();
        u=p.x;
        if(vis[u]) continue;
        vis[u]=true;
        if(to[u]==n) return d[u];
        for(int i=head[to[u]];i!=-1;i=pre[i])
        {
            ll cost=d[u]+w[i]+abs(c[u]-c[i]);
            if(!vis[i]&&d[i]>cost)
            {
                d[i]=cost;
                que.push(rec(i,d[i]));
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i) head[i]=-1;
        e=0;
        int x,y,z1,z2;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d%d",&x,&y,&z1,&z2);
            addedge(x,y,z1,z2);
            addedge(y,x,z1,z2);
        }
        printf("%lld\n",dijkstra());
    }
    return 0;
}

