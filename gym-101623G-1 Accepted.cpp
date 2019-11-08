
#include <bits/stdc++.h>;
using namespace std;
#define N 1010
const double PI=acos(-1);
const double eps=1e-10;
struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
}P[N],a[10],b[10];
int n;
double cross(Point &p0,Point &p1,Point &p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
void build(int k,double r,Point a[])
{
    for(int i=0;i<k;++i)
    {
        double ang=2*PI*i/k;
        a[i].x=r*cos(ang);
        a[i].y=r*sin(ang);
    }
}
bool is_in(Point p,Point a[],int k)
{
    a[k]=a[0];
    for(int i=0;i<k;++i)
    {
        if(cross(p,a[i],a[i+1])<eps) return false;
    }
    return true;
}
void calc(int k,double r,int &in,int &out)
{
    build(k,r,a);
    in=out=0;
    for(int i=1;i<=n;++i)
        if(is_in(P[i],a,k)) ++in;
        else ++out;
}
bool is_inner(int k,double r)
{
    int in=0,out=0;
    calc(k,r,in,out);
    return in==0;
}
bool is_outer(int k,double r)
{
    int in=0,out=0;
    calc(k,r,in,out);
    return out==0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf",&P[i].x,&P[i].y);
    int ans_k;
    double ans=0;
    for(int k=3;k<=8;++k)
    {
        double l=0,r=1e8,mid,in_r,out_r,tmp;
        while(r-l>1e-7)
        {
            mid=(l+r)/2;
            if(is_inner(k,mid)) l=mid;
            else r=mid;
        }
        in_r=mid;
        l=0;r=1e8;
        while(r-l>1e-8)
        {
            mid=(l+r)/2;
            if(is_outer(k,mid)) r=mid;
            else l=mid;
        }
        out_r=mid;
        tmp=(in_r*in_r)/(out_r*out_r);
//        printf("%.3f %.3f\n",in_r,out_r);
        if(tmp>ans)
        {
            ans=tmp;ans_k=k;
        }
    }
    printf("%d %.10f\n",ans_k,ans);
    return 0;
}
/*
9
-4 -1
-4 6
-3 -6
-3 4
0 -4
2 -3
2 3
5 1
7 0

4
1 0
0 1
-1 0
0 -1

1
0 0
*/

