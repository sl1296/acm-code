
#include <bits/stdc++.h>
using namespace std;
#define N 10010
#define M 1000010
typedef long long ll;
const int inf=0x3f3f3f3f;
struct node{
    int c,v;
    node(){}
    node(int c,int v):c(c),v(v){}
    bool operator<(const node &a)const
    {
        return c<a.c||c==a.c&&v>a.v;
    }
    bool operator>(const node &a)const
    {
        return c>a.c||c==a.c&&v<a.v;
    }
}d[N],w[M];
struct rec{
    int x;
    node w;
    rec(){}
    rec(int x,node w):x(x),w(w){}
    bool operator<(const rec &a)const
    {
        return w>a.w;
    }
};
int head[N],to[M],pre[M],ru[N];
bool vis[N];
ll dp[N];
int n,m,e;
map<string,int> mp;
void addedge(int x,int y,node z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
void dijkstra()
{
    for(int i=1;i<=n;++i) d[i]=node(inf,0);
    memset(vis,0,sizeof(vis));
    priority_queue<rec> que;
    for(int i=1;i<=n;++i)
        if(ru[i]==0)
        {
            d[i]=node(0,0);
            que.push(rec(i,d[i]));
        }
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
            node cost=node(d[x].c+w[i].c,d[x].v+w[i].v);
            if(cost<d[y])
            {
                d[y]=cost;
                que.push(rec(y,d[y]));
            }
        }
    }
}
int main()
{
    memset(ru,0,sizeof(ru));
    memset(head,-1,sizeof(head));
    e=0;
    int B,x,y,z1,z2;
    scanf("%d",&B);
    scanf("%d",&m);
    n=0;
    char st[30];
    for(int i=1;i<=m;++i)
    {
        scanf("%s",st);
        if(mp[st]==0) mp[st]=++n;
        x=mp[st];
        scanf("%s",st);
        if(mp[st]==0) mp[st]=++n;
        y=mp[st];
        scanf("%s",st);
        scanf("%d%d",&z1,&z2);
        addedge(y,x,node(z1,z2));
        ++ru[x];
    }
    dijkstra();
    for(int i=1;i<=n;++i)
        for(int j=B;j>=d[i].c;--j)
            dp[j]=max(dp[j],dp[j-d[i].c]+d[i].v);
    ll mx=0;
    int ans=0;
    for(int i=0;i<=B;++i)
        if(dp[i]>mx)
        {
            mx=dp[i];ans=i;
        }
    printf("%lld\n%d\n",mx,ans);
    return 0;
}
/*
15
6
pizza_tomato pizza_base tomato 1 2
pizza_cheese pizza_base cheese 5 10
pizza_classic pizza_tomato cheese 5 5
pizza_classic pizza_cheese tomato 1 2
pizza_salami pizza_classic salami 7 6
pizza_spicy pizza_tomato chili 3 1
*/

