
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
bool operator < (const Point& a,const Point& b){
    return dcmp(a.x-b.x)<0||zero(a.x-b.x)&&dcmp(a.y-b.y)<0;
}
inline double Dis(const Point& a,const Point& b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline int dots_inline(const Point& p1,const Point& p2,const Point& p3){
    return zero(Cross(p1-p3,p2-p3));
}
struct node{
    Point p;
    int id;
    bool operator < (const node &q) const{
        return p<q.p;
    }
};
node p[100010];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].p.x,&p[i].p.y);
            p[i].id=i+1;
        }
        sort(p,p+n);
        for(int i=2;i<n;i++){
            if(!dots_inline(p[i-2].p,p[i-1].p,p[i].p)){
                printf("%d %d %d\n",p[i-2].id,p[i-1].id,p[i].id);
                break;
            }
        }
    }
    return 0;
}

