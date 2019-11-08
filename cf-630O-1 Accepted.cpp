
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define eps 1e-10
#define PI 3.14159265358979323846
#define zero(x)(((x)>0?(x):-(x))<eps)
#define dcmp(x)((x)>eps?1:((x)<-eps?-1:0))
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Point operator + (const Point& a,const Point& b){return Point(a.x+b.x,a.y+b.y);}
Point operator - (const Point& a,const Point& b){return Point(a.x-b.x,a.y-b.y);}
Point operator * (const Point& a,const double& p){return Point(a.x*p,a.y*p);}
Point operator / (const Point& a,const double& p){return Point(a.x/p,a.y/p);}
inline double Dot(const Vector& a,const Vector& b){return a.x*b.x+a.y*b.y;}
inline double Length(const Vector& a){return sqrt(Dot(a,a));}
inline Vector Rotate(const Vector& a,const double& rad){
    return Vector(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
Point re[10];
int main(){
    double e,f,g,h,a,b,c,d;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&e,&f,&g,&h,&a,&b,&c,&d)){
        Point p=Point(e,f);
        Vector up=Vector(g,h);up=up/Length(up);
        Vector left=Rotate(up,PI/2);
        re[0]=p+up*b;
        re[1]=p+left*(a/2);
        re[6]=p+left*(-a/2);
        re[2]=p+left*(c/2);
        re[5]=p+left*(-c/2);
        re[3]=re[2]+up*(-d);
        re[4]=re[5]+up*(-d);
        for(int i=0;i<7;i++){
            printf("%.12f %.12f\n",re[i].x,re[i].y);
        }
    }
    return 0;
}

