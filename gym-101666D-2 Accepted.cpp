
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 2000010
typedef long long ll;
const ll inf=1e18;
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
int head[N],to[M],pre[M],w[M];
bool f[M],vis[N];
int nxt[N],id[N];
ll d[N];
vector<int> edge;
int n,m,e;
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];f[e]=true;head[x]=e++;
}
ll dijkstra(int s,int t)
{
    for(int i=0;i<n;++i)
    {
        vis[i]=false;d[i]=inf;id[i]=-1;
    }
    priority_queue<rec> que;
    d[s]=0;que.push(rec(s,0));
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        int x=p.x;
        if(x==t) return d[x];
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=pre[i])
            if(f[i])
            {
                int y=to[i];
                ll cost=d[x]+w[i];
                if(!vis[y]&&d[y]>cost)
                {
                    d[y]=cost;
                    que.push(rec(y,d[y]));
                    nxt[y]=x;id[y]=i^1;
                }
            }
    }
    return inf;
}
int main()
{
    int x,y,z;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        head[i]=-1;
    e=0;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);addedge(y,x,z);
    }
    dijkstra(1,-1);
    for(int i=0;i<n;++i)
        if(id[i]!=-1) f[id[i]]=false;
    ll dis=dijkstra(0,1);
    if(dis==inf)
    {
        printf("impossible\n");
        return 0;
    }
    vector<int> vec;
    for(x=1;x;x=nxt[x])
        vec.push_back(x);
    vec.push_back(0);
    printf("%d",vec.size());
    for(int i=vec.size()-1;i>=0;--i)
        printf(" %d",vec[i]);
    return 0;
}

