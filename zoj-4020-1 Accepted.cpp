
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define N 100010
const int fx[2][2][2]={{{1,0},{-1,0}},{{0,1},{0,-1}}};
const int inf=0x3f3f3f3f;
struct rec{
    int x,y,k,w;
    rec(){}
    rec(int x,int y,int k,int w):x(x),y(y),k(k),w(w){}
    bool operator<(const rec &a)const
    {
        return w>a.w;
    }
};
vector<int> g[N];
vector<int> d[2][N];
vector<bool> vis[2][N];
int n,m;
int sx,sy,tx,ty;
bool check(int x,int y)
{
    return 0<=x&&x<n&&0<=y&&y<m;
}
int bfs()
{
    queue<rec> que;
    que.push(rec(sx,sy,0,0));
    d[0][sx][sy]=0;vis[0][sx][sy]=true;
    while(!que.empty())
    {
        rec p=que.front();
        que.pop();
        int x=p.x,y=p.y,k=p.k;
//        printf("%d %d %d %d ?\n",x,y,k,p.w);
        if(x==tx&&y==ty) return d[k][x][y];
        int z=g[x][y]^k;
        for(int i=0;i<2;++i)
        {
            int xx=x+fx[z][i][0],yy=y+fx[z][i][1];
            if(!check(xx,yy)) continue;
            int cost=p.w+1;
//            printf("%d %d %d %d !!\n",k^1,xx,yy,vis[k^1][xx].size());
            if(!vis[k^1][xx][yy])
            {
//                printf("%d %d %d #\n",k^1,xx,yy);
                d[k^1][xx][yy]=cost;
                vis[k^1][xx][yy]=true;
                que.push(rec(xx,yy,k^1,cost));
            }
//            printf("ok\n");
        }
    }
    return -1;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;++i)
        {
            g[i]=vector<int>(m);
            d[0][i]=vector<int>(m);
            d[1][i]=vector<int>(m);
            vis[0][i]=vector<bool>(m);
            vis[1][i]=vector<bool>(m);
            for(int j=0;j<m;++j)
            {
                scanf("%d",&g[i][j]);
                d[0][i][j]=d[1][i][j]=inf;
            }
        }
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        --sx;--sy;--tx;--ty;
        printf("%d\n",bfs());
        for(int i=0;i<n;++i)
        {
            g[i].clear();
            d[0][i].clear();d[1][i].clear();
            vis[0][i].clear();vis[1][i].clear();
        }
    }
}

