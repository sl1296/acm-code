
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct rec{
    int x,id;
    rec(){}
    rec(int x,int id):x(x),id(id){}
};
vector<rec> g1[N],g2[N];
bool vis[N],f[N];
int a[N],b[N];
int n,m;
void dfs(int x,vector<rec> g[])
{
    vis[x]=true;
    for(auto e:g[x])
    {
        if(vis[e.x]) continue;
        f[e.id]=true;
        dfs(e.x,g);
    }
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)
        {
            g1[i].clear();g2[i].clear();
        }
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&a[i],&b[i]);
            g1[a[i]].push_back(rec(b[i],i));
            g2[b[i]].push_back(rec(a[i],i));
            f[i]=false;
        }
        for(int i=1;i<=n;++i) vis[i]=false;
        dfs(1,g1);
        for(int i=1;i<=n;++i) vis[i]=false;
        dfs(1,g2);
        int cnt=0;
        for(int i=1;i<=m;++i)
            if(!f[i])
            {
                ++cnt;
                printf("%d %d\n",a[i],b[i]);
                if(cnt==m-2*n) break;
            }
    }
    return 0;
}
/*
1
4 9
1 2
1 3
2 3
2 4
3 2
3 4
4 1
4 2
4 3
*/

