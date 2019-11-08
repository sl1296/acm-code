
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
#define M 400010
struct rec{
    int x,k;
    ll w;
    rec(){}
    rec(int x,int k,ll w):x(x),k(k),w(w){}
    bool operator<(const rec &a)const
    {
        return w>a.w;
    }
};
int head[N],to[M],w[M],pre[M];
int n,m,k,e;
ll d[N][11];
bool vis[N][11];
const ll inf=1000000000000000000LL;
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
ll dijkstra()
{
    priority_queue<rec> que;
    for(int i=1;i<=n;++i)
        for(int j=0;j<=k;++j)
        {
            d[i][j]=inf;vis[i][j]=false;
        }
    d[1][0]=0;que.push(rec(1,0,0));
    while(!que.empty())
    {
        rec p=que.top();que.pop();
        int x=p.x;
        if(vis[x][p.k]) continue;
        vis[x][p.k]=true;
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            ll cost=d[x][p.k]+w[i];
            if(!vis[y][p.k]&&d[y][p.k]>cost)
            {
                d[y][p.k]=cost;
                que.push(rec(y,p.k,cost));
            }
            cost=d[x][p.k];
            if(p.k<k&&!vis[y][p.k+1]&&d[y][p.k+1]>cost)
            {
                d[y][p.k+1]=cost;
                que.push(rec(y,p.k+1,cost));
            }
        }
    }
    ll ans=inf;
    for(int i=0;i<=k;++i)
        ans=min(ans,d[n][i]);
    return ans;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;++i) head[i]=-1;
        e=0;
        int x,y,z;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            addedge(x,y,z);
            addedge(y,x,z);
        }
        printf("%lld\n",dijkstra());
    }
    return 0;
}

