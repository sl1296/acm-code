
#include<cstdio>
#include<cmath>
#include<algorithm>
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
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
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
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        double a,b,c,d,e,f,g,h;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&g,&h);
        Line t=Line(Point(a,b),Point(c,d));
        Point x1=Point(min(e,g),min(f,h));
        Point x2=Point(min(e,g),max(f,h));
        Point x3=Point(max(e,g),max(f,h));
        Point x4=Point(max(e,g),min(f,h));
        Line l1=Line(x1,x2);
        Line l2=Line(x2,x3);
        Line l3=Line(x3,x4);
        Line l4=Line(x4,x1);
        bool ans=false;
        if(intersect_in(t,l1))ans=true;
        if(intersect_in(t,l2))ans=true;
        if(intersect_in(t,l3))ans=true;
        if(intersect_in(t,l4))ans=true;
        if(ans){
            printf("T\n");
        }else{
            printf("F\n");
        }
    }
    return 0;
}

