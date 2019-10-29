
#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define M 10010
typedef long long ll;
const ll inf=1e17;
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
int head[N],to[M],w[M],pre[M],a[N],b[N],u[N];
int n,m,q,e;
bool vis[N];
ll d[N][N],tim[N][N],start[N][N],wait[N][N],dp[N];
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
priority_queue<rec> que;
void dij(int s)
{
    for(int i=1;i<=n;++i)
    {
        d[s][i]=inf;vis[i]=false;
    }
    d[s][s]=0;que.push(rec(s,0));
    while(!que.empty())
    {
        rec p=que.top();que.pop();
        int x=p.x;
        if(vis[x]) continue;
        vis[x]=true;
        for(int i=head[x];i!=-1;i=pre[i])
        {
            int y=to[i];
            ll cost=d[s][x]+w[i];
            if(!vis[y]&&cost<d[s][y])
            {
                d[s][y]=cost;que.push(rec(y,d[s][y]));
            }
        }
    }
}
void print_d()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            printf("%lld ",d[i][j]);
        printf("\n");
    }
}
bool check(ll t)
{
    for(int i=1;i<=q;++i) dp[i]=inf;
    dp[0]=0;
    for(int i=1;i<=q;++i)
    {
        for(int j=1;j<=i;++j)
        {
            ll tmp=max(dp[j-1],start[j][i]);
            if(tmp-start[j][i]+wait[j][i]<=t)
                dp[i]=min(dp[i],tmp+tim[j][i]);
        }
//        printf("%lld ?\n",dp[i]);
    }
    return dp[q]<inf;
}
void print_tim()
{
    for(int i=1;i<=q;++i)
    {
        for(int j=1;j<=q;++j)
            printf("%lld ",tim[i][j]);
        printf("\n");
    }
}
void print_wait()
{
    for(int i=1;i<=q;++i)
    {
        for(int j=1;j<=q;++j)
            printf("%lld ",wait[i][j]);
        printf("\n");
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) head[i]=-1;
    e=0;
    int x,y,z;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    for(int i=1;i<=n;++i) dij(i);
//    print_d();
    scanf("%d",&q);
    for(int i=1;i<=q;++i)
        scanf("%d%d%d",&a[i],&u[i],&b[i]);
    for(int len=1;len<=q;++len)
    {
        for(int i=1;i+len-1<=q;++i)
        {
            int j=i+len-1;
            start[i][j]=b[j];
            ll t=0;
            wait[i][j]=0;
            for(int k=i;k<=j;++k)
            {
                if(k==i) t+=d[1][u[k]];
                else t+=d[u[k-1]][u[k]];
                wait[i][j]=max(wait[i][j],start[i][j]+t-a[k]);
            }
            t+=d[u[j]][1];
            tim[i][j]=t;
        }
    }
//    print_tim();
//    print_wait();
//    printf("%d ?\n",check(5));
    ll l=0,r=inf,mid;
    while(l+1<r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    if(check(l)) printf("%I64d\n",l);
    else printf("%I64d\n",r);
    return 0;
}

