
#include <bits/stdc++.h>
using namespace std;
#define N 30
vector<int> g[N];
int c[N];
int n,m;
bool dfs(int x)
{
    if(x==n) return true;
    for(int i=0;i<3;++i)
    {
        bool flag=true;
        for(int y:g[x])
            if(c[y]==i)
            {
                flag=false;break;
            }
        if(!flag) continue;
        c[x]=i;
        if(dfs(x+1)) return true;
        c[x]=-1;
    }
    return false;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i) g[i].clear();
        int x,y;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(y);
            g[y].push_back(x);
        }
        memset(c,-1,sizeof(c));
        c[0]=0;
        if(dfs(1)) puts("Y");
        else puts("N");
    }
    return 0;
}
/*
1
4
6
0 1
0 2
0 3
1 2
1 3
2 3

4
6
6
0 3
1 5
3 2
2 5
0 4
1 0
7
12
6 5
0 3
2 6
3 5
5 0
0 4
4 5
6 3
1 4
1 2
3 4
2 3
7
8
6 5
0 3
2 6
3 5
1 4
1 2
3 4
2 3
6
9
0 1
1 2
2 3
5 2
5 3
3 4
2 4
1 4
4 5
*/

