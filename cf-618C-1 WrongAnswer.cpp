
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
inline double Dis(const Point& a,const Point& b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline int dots_inline(const Point& p1,const Point& p2,const Point& p3){
    return zero(Cross(p1-p3,p2-p3));
}
Point p[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
        }
        printf("1");
        double mx=1e100;
        int pos;
        for(int i=2;i<=n;i++){
            double now=Dis(p[i],p[1]);
            if(dcmp(mx-now)>0){
                mx=now;
                pos=i;
            }
        }
        printf(" %d",pos);
        double dis=1e100;
        int add;
        for(int i=2;i<=n;i++){
            if(dots_inline(p[0],p[pos],p[i]))continue;
            double now=Dis(p[0],p[i]);
            if(dcmp(dis-now)>0){
                dis=now;
                add=i;
            }
        }
        printf(" %d\n",add);
    }
    return 0;
}

