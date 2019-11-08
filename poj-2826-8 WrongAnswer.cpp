
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=1e-10;
int dcmp(double x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double p){return Vector(a.x*p,a.y*p);}
Vector operator / (Vector a,double p){return Vector(a.x/p,a.y/p);}
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
//叉积长度
//求矢量[p0,p1],[p0,p2]的叉积,p0是顶点,Cross(p1-p0,p2-p0)
//若结果等于0，则这三点共线
//若结果大于0，则p0p2(b)在p0p1(a)的逆时针方向
//若结果小于0，则p0p2(b)在p0p1(a)的顺时针方向
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
bool isLine(Vector a,Vector b){return dcmp(Cross(a,b))==0;}
int dots_inline(Point p1,Point p2,Point p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(Point pp,Point bb){
        p=pp;b=bb;v=b-p;
    }
};
bool dot_online_in(Point p,Line l){
    return dcmp(Cross(p-l.b,l.p-l.b))==0&&(l.p.x-p.x)*(l.b.x-p.x)<eps&&(l.p.y-p.y)*(l.b.y-p.y)<eps;
}
bool same_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)>eps;
}
bool intersect_in(Line u,Line v){
    if(!dots_inline(u.p,u.b,v.p)||!dots_inline(u.p,u.b,v.b))
        return!same_side(u.p,u.b,v)&&!same_side(v.p,v.b,u);
    return dot_online_in(u.p,v)||dot_online_in(u.b,v)||dot_online_in(v.p,u)||dot_online_in(v.b,u);
}
Point LineInter(Line a,Line b){
    double t=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        double a,b,c,d,e,f,g,h;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);
        if(dcmp(b-d)>0){swap(a,c);swap(b,d);}
        if(dcmp(f-h)>0){swap(e,g);swap(f,h);}
        Line u=Line(Point(a,b),Point(c,d)),v=Line(Point(e,f),Point(g,h));
        double ans=0;
        if(!isLine(u.v,v.v)&&intersect_in(u,v)){
            if(dcmp(u.v.y)&&dcmp(v.v.y)){
                if(Cross(u.v,v.v)>0)swap(u,v);
                if(dcmp(u.b.x-v.b.x)<0){
                    Point up=Point(0,min(u.b.y,v.b.y)),ut=Point(1,up.y);
                    Line q=Line(up,ut);
                    Point down=LineInter(u,v);
                    Point ux=LineInter(q,u),vx=LineInter(q,v);
                    ans=(ux.y-down.y)*(vx.x-ux.x)/2;
                }
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

