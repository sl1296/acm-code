
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 5300
int link[N],vis[N],tlink[N];
vector<int>g[N];
int a[N];
int n;
char st[N];
bool dfs(int x,int fa)
{
    int y;
    for(int i=0;i<g[x].size();++i)
    {
        y=g[x][i];
        if(vis[y]!=fa)
        {
            vis[y]=fa;
            if(link[y]==-1||dfs(link[y],fa))
            {
                link[y]=x;tlink[x]=y;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        int t=0;
        for(int i=1;i<=26;++i)
        {
            int z;
            scanf("%d",&z);
            for(int j=0;j<z;++j)
                a[++t]=i;
        }
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=1;i<=n;++i)
            for(int j=1;j<=t;++j)
                if(i%a[j]==0) g[i].push_back(j);
        memset(link,-1,sizeof(link));
        memset(tlink,-1,sizeof(tlink));
        memset(vis,-1,sizeof(vis));
        int ans=0;
        for(int i=n;i>0;--i)
            if(dfs(i,i)) ++ans;
        if(ans==n)
        {
            for(int i=1;i<=n;++i)
                st[i-1]=a[tlink[i]]-1+'a';
            st[n]='\0';
            puts(st);
        }
        else puts("#rekt");
    }
    return 0;
}
/*
3
3
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
6
5 2 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
10
1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/

