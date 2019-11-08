
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#include<stack>
#include<cstring>
#include<vector>
#include<list>
#include<set>
#include<map>
using namespace std;
#define LL __int64
#define pi (4*atan(1.0))
#define eps 1e-8
#define bug(x)  cout<<"bug"<<x<<endl;
const int N=3e5+10,M=2e6+10,inf=1e9+10;
const LL INF=1e18+10,mod=1e9+7;

struct isss
{
    int v,nex;
}edge[N<<1];
int head[N],edg;
int in[N],out[N],tot;
LL deep[N];
void add(int u,int v)
{
    ++edg;
    edge[edg].v=v;
    edge[edg].nex=head[u];
    head[u]=edg;
}
void dfs(int u,int fa,int dp)
{
    in[u]=++tot;
    deep[u]=dp;
    for(int i=head[u];i;i=edge[i].nex)
    {
        int v=edge[i].v;
        if(v==fa)continue;
        dfs(v,u,dp+1);
    }
    out[u]=tot;
}
struct AYT
{
    LL tree[N];
    void init()
    {
        memset(tree,0,sizeof(tree));
    }
    int lowbit(int x)
    {
        return x&-x;
    }
    void update(int x,LL c)
    {
        while(x<N)
        {
            tree[x]+=c;
            x+=lowbit(x);
        }
    }
    LL query(int x)
    {
        LL ans=0;
        while(x)
        {
            ans+=tree[x];
            x-=lowbit(x);
        }
        return ans;
    }
}TX,TK;

void init()
{
    tot=0;
    memset(head,0,sizeof(head));
    memset(deep,0,sizeof(deep));
    TX.init();
    TK.init();
    edg=0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        init();
        for(int i=2;i<=n;i++)
        {
            int f;
            scanf("%d",&f);
            add(f,i);
            add(i,f);
        }
        dfs(1,-1,0);
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int t,v;
            LL x,k;
            scanf("%d%d",&t,&v);
            if(t==1)
            {
                scanf("%I64d%I64d",&x,&k);
                x+=1LL*deep[v]*k;
                x%=mod;
                TX.update(in[v],x);
                TX.update(out[v]+1,-x);
                TK.update(in[v],k);
                TK.update(out[v]+1,-k);
            }
            else
            {
                LL xx=TX.query(in[v]);
                LL y=TK.query(in[v]);
                y%=mod;
                LL ans=xx-1LL*deep[v]*y;
                ans%=mod;ans+=mod;ans%=mod;
                printf("%I64d\n",ans);
            }
        }
    }
    return 0;
}


