
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll inf=1e15;
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
ll d1[N],d2[N];
bool f[N],vis[N];
int a[N],b[N],c[N],head1[N],head2[N],to[N*2],w[N*2],pre[N*2],ru[N],sta1[N],sta2[N];
int n,m,e,cnt,root,tot;
int dfn[N],low[N];
vector<int> g[N];
void addedge1(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head1[x];head1[x]=e++;
}
void addedge2(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head2[x];head2[x]=e++;
}
priority_queue<rec> que;
void dij(int s,ll d[],int head[])
{
    for(int i=1;i<=n;++i)
    {
        d[i]=inf;vis[i]=false;
    }
    que.push(rec(s,0));d[s]=0;
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        int x=p.x;
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            ll cost=d[x]+w[i];
            if(!vis[y]&&cost<d[y])
            {
                d[y]=cost;
                que.push(rec(y,d[y]));
            }
        }
    }
}
void tarjan(int x)
{
    int y;
    dfn[x]=low[x]=++cnt;
    for(int i=0;i<g[x].size();i++)
    {
        y=g[x][i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
            if(x!=1&&low[y]>=dfn[x])
                f[x]=true;
            else if(x==1) ++root;
        }
        else low[x]=min(low[x],dfn[y]);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        head1[i]=head2[i]=-1;
        g[i].clear();
        dfn[i]=low[i]=f[i]=0;
    }
    e=0;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        addedge1(a[i],b[i],c[i]);
        addedge2(b[i],a[i],c[i]);
    }
    dij(1,d1,head1);
    dij(2,d2,head2);
    for(int i=1;i<=m;++i)
        if(d1[a[i]]+c[i]+d2[b[i]]==d1[2])
        {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
//            printf("%d %d #\n",a[i],b[i]);
        }
    cnt=tot=root=0;
    tarjan(1);
    f[1]=f[2]=true;
//    for(int i=1;i<=n;++i) printf("%d ",f[i]);printf("\n");
    for(int i=1;i<=m;++i)
    {
//        printf("%d %d %d %lld %lld %lld %lld %d %d ?\n",a[i],b[i],c[i],d1[a[i]],d1[b[i]],d2[a[i]],d2[b[i]],f[a[i]],f[b[i]]);
        if(d1[b[i]]+c[i]+d2[a[i]]<d1[2]) puts("HAPPY");
        else if(d1[a[i]]+c[i]+d2[b[i]]==d1[2]&&f[a[i]]&&f[b[i]]) puts("SAD");
        else puts("SOSO");
    }
    return 0;
}
/*
4 5
1 3 5
3 4 6
4 2 7
2 1 18
2 3 12

6 6
1 3 1
1 4 1
3 6 5
4 5 2
5 6 3
6 2 1
*/

