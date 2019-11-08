
#include <bits/stdc++.h>
using namespace std;
#define N 260
int link[N],tlink[N],vis[N];
double a1[N],b1[N],a2[N],b2[N],d[N][N];
int visx[N],visy[N];
vector<int>g[N];
int n,m1,m2;
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
int solve(double mid)
{
    memset(link,-1,sizeof(link));
    memset(tlink,-1,sizeof(tlink));
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=m1;++i) g[i].clear();
    for(int i=1;i<=m1;++i)
        for(int j=1;j<=m2;++j)
            if(d[i][j]<=mid)
                g[i].push_back(j);
    int ans=0;
    for(int i=1;i<=m1;++i)
        if(dfs(i,i)) ++ans;
    return m1+m2-ans;
}
double dis2(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
    int x,y,k;
    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=1;i<=m1;++i) scanf("%lf%lf",&a1[i],&b1[i]);
    for(int i=1;i<=m2;++i) scanf("%lf%lf",&a2[i],&b2[i]);
    for(int i=1;i<=m1;++i)
        for(int j=1;j<=m2;++j)
            d[i][j]=dis2(a1[i],b1[i],a2[j],b2[j]);
//    printf("%d ?\n",solve(1.9));
    double l=0,r=1e5,mid;
    while(r-l>1e-7)
    {
        mid=(l+r)/2;
        if(solve(mid*mid)>=n) l=mid;
        else r=mid;
    }
    printf("%.8f\n",mid);
    return 0;
}



