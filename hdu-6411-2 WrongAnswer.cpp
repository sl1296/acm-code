


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int head[N],to[N*2],pre[N*2],v[N],a[N];
int num[32];
int n,m,e,t;
bool vis[N];
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
void dfs(int x)
{
    vis[x]=true;a[++t]=v[x];
    for(int i=head[x];i!=-1;i=pre[i])
    {
        int y=to[i];
        if(vis[y]) continue;
        dfs(y);
    }
}
int main()
{
    int ca,x,y;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
            scanf("%d",&v[i]);
        for(int i=1;i<=n;++i)
        {
            head[i]=-1;vis[i]=false;
        }
        e=0;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);
            addedge(y,x);
        }
        ll ans=0;
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                t=0;
                dfs(i);
                sort(a+1,a+t+1);
                memset(num,0,sizeof(num));
                for(int j=1;j<=t;++j)
                {
                    for(int k=0;k<=30;++k)
                        if((a[j]>>k)&1)
                        {
                            ans+=(ll)a[j]*num[k]*(1LL<<k);
                            ++num[k];
                        }
                }
            }
        printf("%I64d\n",ans);
    }
    return 0;
}
/*
2
5 5
3 9 4 8 9
2 1
1 3
2 1
1 2
5 2
5 0
3 9 4 8 9
*/


