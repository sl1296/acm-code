
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 5300
int num[N],link[N],vis[N],tlink[N];
vector<int>g[N];
int a[N],b[N];
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
int calc(int k)
{
    int t=0;
    for(int i=1;i<=26;++i)
    {
        for(int j=0;j<num[i];++j)
            a[++t]=i;
    }
    for(int i=1;i<=n;++i) g[i].clear();
    for(int i=k;i<=n;++i)
        for(int j=1;j<=t;++j)
            if(i%a[j]==0) g[i].push_back(j);
    memset(link,-1,sizeof(link));
    memset(tlink,-1,sizeof(tlink));
    memset(vis,-1,sizeof(vis));
    int ans=0;
    for(int i=k;i<=n;++i)
        if(dfs(i,i)) ++ans;
    return ans;
}
bool flag;
bool solve(int dep)
{
    if(dep>n) return true;
    for(int i=1;i<=26;++i)
        if(num[i]&&dep%i==0)
        {
            --num[i];
            b[dep]=i;
            if(calc(dep+1)==n-dep)
            {
                if(solve(dep+1)) return true;
            }
            ++num[i];
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
            scanf("%d",&num[i]);
//        printf("%d ?\n",calc(1));
        if(solve(1))
        {
            for(int i=1;i<=n;++i)
                printf("%c",b[i]-1+'a');
            printf("\n");
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

