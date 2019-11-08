
#include <bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long ll;
const ll inf=1e15;
struct rec{
    int x,s;
    ll w;
    rec(){}
    rec(int x,int s,ll w):x(x),s(s),w(w){}
    bool operator<(const rec &a)const
    {
        return w>a.w;
    }
};
int head[N],to[N*2],w[N*2],pre[N*2];
ll d[N],ans[N];
int start[N];
int n,m,e,q;
int a[N];
bool vis[N];
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
priority_queue<rec> que;
void dijkstra()
{
    for(int i=0;i<=n;++i)
    {
        d[i]=inf;vis[i]=false;
    }
    for(int i=1;i<=q;++i)
    {
        int x=a[i];
        d[x]=0;start[x]=x;
        que.push(rec(x,x,0));
    }
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        int x=p.x,s=p.s;
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            ll cost=d[x]+w[i];
            if(!vis[y]&&cost<d[y])
            {
                d[y]=cost;start[y]=s;
                que.push(rec(y,s,d[y]));
            }
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=q;++i) scanf("%d",&a[i]);
    memset(head,-1,sizeof(head));
    e=0;
    int x,y,z;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    dijkstra();
    for(int i=1;i<=n;++i) ans[i]=inf;
    for(int x=1;x<=n;++x)
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            if(start[x]!=start[y])
            {
                ans[start[x]]=min(ans[start[x]],d[x]+d[y]+w[i]);
                ans[start[y]]=min(ans[start[y]],d[x]+d[y]+w[i]);
            }
        }
    for(int i=1;i<=q;++i) printf("%lld ",ans[a[i]]);
    return 0;
}
/*
5 6 3
2 4 5
1 2 4
1 3 1
1 4 1
1 5 4
2 3 1
3 4 3
 
3 3 5
*/

