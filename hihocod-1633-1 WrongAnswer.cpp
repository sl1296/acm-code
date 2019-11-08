
#include <bits/stdc++.h>
using namespace std;
#define N 30
#define eps 1e-8
#define zero(x)(((x)>0?(x):-(x))<eps)
#define _sign(x)((x)>eps?1:((x)<-eps?2:0))
typedef pair<int,int> pii;
const int fx[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
struct point
{
    double x,y;
    point(){}
    point(double x,double y):x(x),y(y){}
}P[4];
struct line
{
    point a,b;
    line(){}
    line(point a,point b):a(a),b(b){}
};
bool f[N][N],vis[N][N];
int d[N][N];
int n;
bool flag;
double xmult(point p1,point p2,point p0)
{
    return(p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
//判三点共线
int dots_inline(point p1,point p2,point p3)
{
    return zero(xmult(p1,p2,p3));
}
//判点是否在线段上,包括端点
int dot_online_in(point p,line l)
{
    return zero(xmult(p,l.a,l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//判两点在线段同侧,点在线段上返回0
int same_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)>eps;
}
//判两线段相交,包括端点和部分重合
int intersect_in(line u,line v)
{
    if(!dots_inline(u.a,u.b,v.a)||!dots_inline(u.a,u.b,v.b))
        return!same_side(u.a,u.b,v)&&!same_side(v.a,v.b,u);
    return dot_online_in(u.a,v)||dot_online_in(u.b,v)||dot_online_in(v.a,u)||dot_online_in(v.b,u);
}
//判两点在线段异侧,点在线段上返回0
int opposite_side(point p1,point p2,line l)
{
    return xmult(l.a,p1,l.b)*xmult(l.a,p2,l.b)<-eps;
}
//判两线段相交,不包括端点和部分重合
int intersect_ex(line u,line v)
{
    return opposite_side(u.a,u.b,v)&&opposite_side(v.a,v.b,u);
}
bool in_triangle(point p)
{
    if(flag) return false;
    for(int i=0;i<3;++i)
        if(xmult(P[i],P[i+1],p)<eps) return false;
    return true;
}
bool intersect_triangle(point a,point b)
{
    if(flag) return false;
    line l=line(a,b);
    for(int i=0;i<3;++i)
        if(intersect_ex(l,line(P[i],P[i+1]))) return true;
    point mid=point((a.x+b.x)/2,(a.y+b.y)/2);
    if(in_triangle(mid)) return true;
    return false;
}
bool in_border(int x,int y)
{
    return 0<=x&&x<n&&0<=y&&y<n;
}
int bfs()
{
    queue<pii> que;
    memset(vis,0,sizeof(vis));
    d[0][0]=0;vis[0][0]=true;
    que.push({0,0});
    while(!que.empty())
    {
        pii p=que.front();
        que.pop();
        int x=p.first,y=p.second;
        if(x==n-1&&y==n-1) return d[x][y];
        for(int i=0;i<8;++i)
        {
            int xx=x+fx[i][0],yy=y+fx[i][1];

            if(!in_border(xx,yy)||!f[xx][yy]||vis[xx][yy]) continue;
            if(intersect_triangle(point(x,y),point(xx,yy))) continue;
            vis[xx][yy]=true;d[xx][yy]=d[x][y]+1;
            que.push({xx,yy});
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<3;++i)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        if(xmult(P[1],P[2],P[0])<eps) swap(P[1],P[2]);
        P[3]=P[0];
        if(zero(xmult(P[0],P[1],P[2]))) flag=true;
        else flag=false;
        for(int i=0;i<n;++i)
        {
            char st[30];
            scanf("%s",st);
            for(int j=0;j<n;++j)
            {
                int x=j,y=n-i-1;
                if(st[j]=='.')
                {
                    if(in_triangle(point(x,y)))
                        f[x][y]=false;
                    else f[x][y]=true;
                }
                else f[x][y]=false;
            }
        }
        if(!f[0][0]) printf("-1\n");
        else printf("%d\n",bfs());
    }
    return 0;
}
/*
3
1 -1 1 2 1 3
...
...
...
1 -1 1 2 1 3
...
...
#..
*/

