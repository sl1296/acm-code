
#include <bits/stdc++.h>
using namespace std;
#define N 3010
#define M 2000010
bool prime[M],f[N],ma[N];
int n;
int link[N],tlink[N],vis[N];
/*
visx[]和visy[]分别表示X集合和Y集合的点是否被覆盖，
在求最小点覆盖时才需要用到
*/
int visx[N],visy[N];
vector<int>g[N];
int a[N];
bool dfs(int x,int fa)
{
    int y;visx[x]=true;
    for(int i=0;i<g[x].size();++i)
    {
        y=g[x][i];
        if(vis[y]!=fa)
        {
            vis[y]=fa;visy[y]=true;
            if(link[y]==-1||dfs(link[y],fa))
            {
                link[y]=x;tlink[x]=y;
                return true;
            }
        }
    }
    return false;
}
void init()
{
    memset(prime,1,sizeof(prime));
    for(int i=2;i<M;++i)
        if(prime[i])
        {
            for(int j=i+i;j<M;j+=i)
                prime[j]=false;
        }
}
int main()
{
    init();
    int ca,k;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            g[i].clear();
        }
        memset(f,0,sizeof(f));
        bool flag=false;
        for(int i=1;i<=n;++i)
            if(a[i]&1)
                for(int j=1;j<=n;++j)
                    if(prime[a[i]+a[j]]&&a[i]!=a[j])
                    {
                        g[i].push_back(j);
                        f[i]=f[j]=true;
                        if(a[i]==1) flag=true;
                    }
        memset(link,-1,sizeof(link));
        memset(tlink,-1,sizeof(tlink));
        memset(vis,-1,sizeof(vis));
        memset(ma,0,sizeof(ma));
        int ans=0;
        for(int i=1;i<=n;++i)
            if((a[i]&1)&&dfs(i,i)) ++ans;
        for(int i=1;i<=n;++i)
            if(link[i]!=-1)
            {
                ma[i]=ma[link[i]]=true;
            }
        int cnt=0;
        for(int i=1;i<=n;++i)
        {
//            printf("i %d %d\n",i,ma[i]);
            if(a[i]==1&&!ma[i])
                ++cnt;
        }
        ans+=cnt/2;
//        printf("%d ?\n",ans);
        if(ans>=k)
        {
            printf("%d\n",k*2);
            continue;
        }
        k-=ans;
        int num=0;
        if((cnt&1)&&flag) num=1;
        for(int i=1;i<=n;++i)
            if(a[i]!=1&&!ma[i]&&f[i])
                ++num;
        if(num>=k) printf("%d\n",ans*2+k);
        else printf("%d\n",ans*2+num);
    }
    return 0;
}

