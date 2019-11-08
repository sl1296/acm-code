
#include <bits/stdc++.h>
using namespace std;
#define N 3010
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
vector<rec> g[N];
int n,m,k;
int a[N];
ll d[N];
bool vis[N];
ll dijkstra(int limit)
{
    for(int i=1;i<=n;++i)
    {
        d[i]=inf;vis[i]=false;
    }
    priority_queue<rec> que;
    d[1]=0;que.push(rec(1,0));
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        int x=p.x;
        if(vis[x]) continue;
        vis[x]=true;
        for(auto e:g[x])
        {
            ll cost;
            if(e.w<limit) cost=p.w;
            else cost=p.w+e.w-limit;
            if(cost<d[e.x])
            {
                d[e.x]=cost;
                que.push(rec(e.x,cost));
            }
        }
    }
    return d[n]+(ll)k*limit;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    int x,y;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&a[i]);
        g[x].push_back(rec(y,a[i]));
        g[y].push_back(rec(x,a[i]));
    }
    ll ans=dijkstra(0);
    for(int i=1;i<=m;++i)
        ans=min(ans,dijkstra(a[i]));
    printf("%I64d\n",ans);
    return 0;
}
/*
6 7 2
1 2 6
2 3 1
2 4 3
2 5 5
3 6 10
4 6 9
5 6 8
*/

