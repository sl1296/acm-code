
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
const ll mod=1e9+7;
int head[N],to[N],pre[N],ru[N],sta[N];
int n,m,e;
int a[N],b[N];
ll dp[N];
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
void Add(ll &x,ll y)
{
    x+=y;
    if(x>=mod) x-=mod;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&a[i],&b[i]);
            head[i]=-1;ru[i]=0;dp[i]=0;
        }
        e=0;
        int x,y;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);++ru[y];
        }
        int top=0;
        ll ans=0;
        for(int i=1;i<=n;++i)
            if(ru[i]==0) sta[++top]=i;
        while(top)
        {
            x=sta[top--];
            Add(ans,dp[x]*b[x]%mod);
            Add(dp[x],a[x]);
            for(int i=head[x];i!=-1;i=pre[i])
            {
                y=to[i];
                Add(dp[y],dp[x]);
                --ru[y];
                if(ru[y]==0)
                {
                    sta[++top]=y;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

