
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 1010
#define M 1000010
const int inf=0x3f3f3f3f;
struct qnode{
    int v,c;
    qnode(){}
    qnode(int v,int c):v(v),c(c){}
    bool operator<(const qnode &a)const
    {
        return c>a.c;
    }
};
int a[N],d[N];
int head[N],to[M],pre[M],val[M];
bool vis[N];
int n,m,e;
void addedge(int x,int y,int z)
{
    to[e]=y;val[e]=z;pre[e]=head[x];head[x]=e++;
}
int dijkstra(int s,int t)
{
    if(s==t) return 0;
    priority_queue<qnode> que;
    for(int i=1;i<=n;++i)
    {
        vis[i]=false;d[i]=inf;
    }
    d[s]=0;
    que.push(qnode(s,0));
    qnode tmp;
    int ans=inf;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i!=-1;i=pre[i])
        {
            int v=to[i],cost=d[u]+val[i];
            if(v==t) ans=min(ans,cost);
            if(a[v])
            {
                int res=cost%(a[v]*2);
                if(res>=a[v]) cost+=a[v]*2-res;
            }
            if(!vis[v]&&d[v]>cost)
            {
                d[v]=cost;
                que.push(qnode(v,d[v]));
            }
        }
    }
    return ans;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        int x,y,z;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            head[i]=-1;
        }
        e=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        int s,t;
        scanf("%d%d",&s,&t);
        printf("%d\n",dijkstra(s,t));
    }
    return 0;
}

