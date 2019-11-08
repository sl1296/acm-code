
#include <bits/stdc++.h>
using namespace std;
#define N 1000010
vector<int> g[N];
int sz[N];
int n;
void dfs(int x,int pa)
{
    sz[x]=1;
    for(int y:g[x])
    {
        if(y==pa) continue;
        dfs(y,x);
        sz[x]+=sz[y];
    }
}
int main()
{
    scanf("%d",&n);
    int x,y;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);
    for(int k=1;k<n;++k)
    {
        if(n%(k+1)==0)
        {
            int z=n/(k+1);
            int cnt=0;
            for(int i=1;i<=n;++i)
                if(sz[i]%z==0) ++cnt;
            if(cnt==k+1) printf("%d ",k);
        }
    }
    return 0;
}
/*
8
1 2
2 3
1 4
4 5
6 7
8 3
7 3
*/

