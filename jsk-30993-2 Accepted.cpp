
//--------------
//点的编号从1到n
//--------------
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2010
struct Point{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
}P[N],b1[N],b2[N];
struct Line{
    Point s,t;
    Line(){}
    Line(Point a,Point b):s(a),t(b){}
};
int n,m;
double r;
const double eps=1e-8;
int sig(double x)
{
    if(x>eps) return 1;
    if(x<-eps) return -1;
    return 0;
}
double cross(Point p0,Point p1,Point p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
Point intersect(Line l1,Line l2)
{
    double u=cross(l2.s,l2.t,l1.s),v=cross(l2.t,l2.s,l1.t);
    Point p;
    p.x=(u*l1.t.x+v*l1.s.x)/(u+v);
    p.y=(u*l1.t.y+v*l1.s.y)/(u+v);
    return p;
}
Line Move(Line l,double r)//将直线向内推进r
{
    double k,dx,dy,tx,ty;
    dx=l.t.x-l.s.x;
    dy=l.t.y-l.s.y;
    k=r/sqrt(dx*dx+dy*dy);
    tx=k*dy;ty=-k*dx;
    l.s.x+=tx;l.s.y+=ty;
    l.t.x+=tx;l.t.y+=ty;
    return l;
}
void cut(Line l)
{
    l=Move(l,r);
    int cnt=0;
    Line l1;
    b1[0]=b1[m];b1[m+1]=b1[1];
    for(int i=1;i<=m;++i)
    {
        if(sig(cross(l.s,l.t,b1[i]))<=0)
            b2[++cnt]=b1[i];
        else
        {
            if(sig(cross(l.s,l.t,b1[i-1]))<0)
                b2[++cnt]=intersect(l,Line(b1[i-1],b1[i]));
            if(sig(cross(l.s,l.t,b1[i+1]))<0)
                b2[++cnt]=intersect(l,Line(b1[i],b1[i+1]));
        }
    }
    for(int i=1;i<=cnt;++i)
        b1[i]=b2[i];
    m=cnt;
}
bool solve1()
{
    P[n+1]=P[1];
    m=n;
    for(int i=1;i<=n;++i) b1[i]=P[i];
    for(int i=1;i<=n;++i)
    {
        cut(Line(P[i],P[i+1]));
        if(m==0) break;
    }
    n=m;
    for(int i=1;i<=n;++i) P[i]=b1[i];
}
double area(Point P[],int n)
{
    double ans=0;
    P[n+1]=P[1];
    for(int i=1;i<=n;++i)
        ans+=cross(P[1],P[i],P[i+1]);
    return -ans/2;
}
void Reverse(Point P[],int n)
{
    for(int i=1;i<=(n+1)/2;++i)
        swap(P[i],P[n-i+1]);
}
double solve2()
{
    if(n<3) return 0;
    double ans=0;
    int i=0,j,k;
    P[0]=P[n];
    for(int i=0;i<n;++i)
    {
        j=(i+1)%n;k=(j+1)%n;
        while(i!=k)
        {
            while(j!=k&&cross(P[i],P[k],P[j])-cross(P[i],P[k],P[j+1])<-eps)
                j=(j+1)%n;
            ans=max(ans,cross(P[i],P[k],P[j]));
            // printf("%d %d %d %.3f !\n",i,j,k,cross(P[i],P[k],P[j]));
            // if(fabs(cross(P[i],P[k],P[j])-2)<eps)
            // {
            //     printf("------------\n");
            //     printf("%.3f %.3f\n",P[i].x,P[i].y);
            //     printf("%.3f %.3f\n",P[j].x,P[j].y);
            //     printf("%.3f %.3f\n",P[k].x,P[k].y);
            // }
            k=(k+1)%n;
        }
    }
    return ans;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%lf",&n,&r);
        for(int i=1;i<=n;++i)
            scanf("%lf%lf",&P[i].x,&P[i].y);
        if(area(P,n)<0) Reverse(P,n);
        solve1();
        // for(int i=1;i<=n;++i) printf("%.3f %.3f ?\n",P[i].x,P[i].y);
        printf("%.8f\n",solve2());
    }
    return 0;
}

