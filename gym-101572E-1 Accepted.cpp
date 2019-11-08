
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 510
typedef long long ll;
const int fx[][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
struct rec{
    int x,y,w;
    rec(){}
    rec(int x,int y,int w):x(x),y(y),w(w){}
    bool operator<(const rec &a)const
    {
        return w<a.w;
    }
};
int a[N][N],b[N][N];
bool vis[N][N];
int n,m;
int ans;
bool check(int x,int y)
{
    return 1<=x&&x<=n&&1<=y&&y<=m;
}
ll solve(int x,int y)
{
    priority_queue<rec> que;
    b[x][y]=-a[x][y];
    que.push(rec(x,y,b[x][y]));
    while(!que.empty())
    {
        rec p=que.top();
        que.pop();
        if(vis[p.x][p.y]) continue;
        vis[p.x][p.y]=true;
        for(int i=0;i<8;++i)
        {
            int x=p.x+fx[i][0],y=p.y+fx[i][1];
            if(!check(x,y)||a[x][y]>=0||vis[x][y]) continue;
            int tmp=min(b[p.x][p.y],-a[x][y]);
            if(b[x][y]<tmp)
            {
                b[x][y]=tmp;
                que.push(rec(x,y,tmp));
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            ans+=b[i][j];
        }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            scanf("%d",&a[i][j]);
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%I64d\n",solve(x,y));
    return 0;
}

