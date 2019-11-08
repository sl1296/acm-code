
#include <bits/stdc++.h>
using namespace std;
#define N 2010
int n,e;
int a[N],b[N],flag[N];
int head[N],to[N*10],pre[N*10];
int link[N],vis[N];
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
void color(int x,int c)
{
    flag[x]=c;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        int y=to[i];
        if(flag[y]!=-1) continue;
        color(y,c^1);
    }
}
bool dfs(int x,int fa)
{
    int y;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        y=to[i];
        if(vis[y]!=fa)
        {
            vis[y]=fa;
            if(link[y]==-1||dfs(link[y],fa))
            {
                link[y]=x;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        e=0;
        for(int i=1;i<=n;++i)
        {
            head[i]=-1;flag[i]=-1;
            link[i]=-1;vis[i]=-1;
        }
        for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                if(i!=j&&abs(a[i]-a[j])+abs(b[i]-b[j])==1)
                {
                    addedge(i,j);addedge(j,i);
                }
        color(1,0);
        int ans=0;
        for(int i=1;i<=n;++i)
            if(flag[i]==0&&dfs(i,i)) ++ans;
        printf("%d\n",n-ans);
    }
    return 0;
}

