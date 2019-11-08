
#include <bits/stdc++.h>
using namespace std;
#define N 50
#define M 1010
#define D 125000
typedef long long ll;
const ll inf=1e15;
ll dp[3][D+1][N],ans[3][D+1];
int head[N],to[M],w[M],pre[M];
int n,m,e;
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    for(int k=0;k<ca;++k)
    {
        memset(head,-1,sizeof(head));
        e=0;
        scanf("%d%d",&n,&m);
        int x,y,z,t;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&z);
            addedge(i,i,z);
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            --x;--y;
            addedge(x,y,z);
        }
        scanf("%d",&t);
        --t;
        for(int i=0;i<=D;++i)
            for(int j=0;j<n;++j)
                dp[k][i][j]=inf;
        dp[k][0][0]=0;
        for(int i=0;i<D;++i)
            for(int x=0;x<n;++x)
                if(dp[k][i][x]<inf)
                    for(int j=head[x];j!=-1;j=pre[j])
                    {
                        int y=to[j];
                        dp[k][i+1][y]=min(dp[k][i+1][y],dp[k][i][x]+w[j]);
                    }
        for(int i=0;i<=D;++i)
            ans[k][i]=dp[k][i][t];
    }
    ll mi=inf;
    for(int i=0;i<=D;++i)
    {
        ll tmp=0;
        for(int k=0;k<ca;++k)
            tmp+=ans[k][i];
        mi=min(mi,tmp);
    }
    printf("%I64d\n",mi);
    return 0;
}

