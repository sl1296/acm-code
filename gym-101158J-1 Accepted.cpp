
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
struct Point{
    double x,y;
    Point(){}
    Point(double x0,double y0):x(x0),y(y0){}
}p[200005];
typedef Point Vector;
struct Line{
    Point s,e;
    Line(){}
    Line(Point s0,Point e0):s(s0),e(e0){}
};
int n;
double R;
const double eps=1e-8;
const double Pi=acos(-1);
double sgn(double x){
    if (x>eps) return 1.0;
    if (x<-eps) return -1.0;
    return 0;
}
Point operator *(Point p1,double x){
    return Point(p1.x*x,p1.y*x);
}
Point operator /(Point p1,double x){
    return Point(p1.x/x,p1.y/x);
}
double operator /(Point p1,Point p2){
    return p1.x*p2.x+p1.y*p2.y;
}
double operator *(Point p1,Point p2){
    return p1.x*p2.y-p1.y*p2.x;
}
Point operator +(Point p1,Point p2){
    return Point(p1.x+p2.x,p1.y+p2.y);
}
Point operator -(Point p1,Point p2){
    return Point(p1.x-p2.x,p1.y-p2.y);
}
bool operator <(const Point &a,const Point &b) {
    return sgn(a.x-b.x)<0||(sgn(a.x-b.x)==0&&sgn(a.y-b.y)<0);
}
bool operator ==(const Point &a,const Point &b) {
    return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
}
double dis(Point p1){
    return sqrt(p1.x*p1.x+p1.y*p1.y);
}
double dis(Point p1,Point p2){
    return dis(Point(p1.x-p2.x,p1.y-p2.y));
}
double Dot(Vector A,Vector B) {
    return A.x*B.x+A.y*B.y;
}
double Length(Vector A) {
    return sqrt(Dot(A,A));
}
double Angle(Vector A,Vector B) {
    return acos(Dot(A,B)/Length(A)/Length(B));
}
double Cross(Vector A,Vector B) {
    return A.x*B.y-A.y*B.x;
}
double sqr(double x){
    return x*x;
}
Vector Unit(Vector A) {
    //直线的单位向量
    double L=Length(A);
    return Vector(A.x/L,A.y/L);
}
struct Line2{
    Point P;
    Vector v;
    double ang;

    Line2() { }  //构造函数
    Line2(Point P,Vector v): P(P), v(v) { ang = atan2(v.y, v.x); }

    bool operator < (const Line2& L) const { //极角排序
        return ang < L.ang;
    }

    Point point(double t) { return P + v*t; }
};
double dist_line(Line p){
    double A,B,C,dist;
    A=p.s.y-p.e.y;
    B=p.s.x-p.e.x;
    C=p.s.x*p.e.y-p.s.y*p.e.x;
    dist=fabs(C)/sqrt(sqr(A)+sqr(B));
    return dist;
}
double get_cos(double a,double b,double c){
    return (b*b+c*c-a*a)/(2*b*c);
}
double get_angle(Point p1,Point p2){
    if (!sgn(dis(p1))||!sgn(dis(p2))) return 0.0;
    double A,B,C;
    A=dis(p1);
    B=dis(p2);
    C=dis(p1,p2);
    if (C<=eps) return 0.0;
    return acos(get_cos(C,A,B));
}
Point get_point(Point p){
    double T=sqr(p.x)+sqr(p.y);
    return Point(sgn(p.x)*sqrt(sqr(p.x)/T),sgn(p.y)*sqrt(sqr(p.y)/T));
}
double S(Point p1,Point p2,Point p3){
    return fabs((p2-p1)*(p3-p1))/2;
}
double work(Point p1,Point p2,Point O){
    p1=p1-O;p2=p2-O;
    O=Point(0,0);
    double f=sgn(p1*p2),res=0;
    if (!sgn(f)||!sgn(dis(p1))||!sgn(dis(p2))) return 0.0;
    double l=dist_line(Line(p1,p2));
    double a=dis(p1);
    double b=dis(p2);
    double c=dis(p1,p2);
    if (a<=R&&b<=R){
        return fabs(p1*p2)/2.0*f;
    }
    if (a>=R&&b>=R&&l>=R){
        double ang=get_angle(p1,p2);
        return fabs((ang/(2.0))*(R*R))*f;
    }
    if (a>=R&&b>=R&&l<=R&&(get_cos(a,b,c)<=0||get_cos(b,a,c)<=0)){
        double ang=get_angle(p1,p2);
        return fabs((ang/(2.0))*(R*R))*f;
    }
    if (a>=R&&b>=R&&l<=R&&(get_cos(a,b,c)>0&&get_cos(b,a,c)>0)){
        double dist=dist_line(Line(p1,p2));
        double len=sqrt(sqr(R)-sqr(dist))*2.0;
        double ang1=get_angle(p1,p2);
        double cos2=get_cos(len,R,R);
        res+=fabs(len*dist/2.0);
        double ang2=ang1-acos(cos2);
        res+=fabs((ang2/(2))*(R*R));
        return res*f;
    }
    if ((a>=R&&b<R)||(a<R&&b>=R)){
        if (b>a) swap(a,b),swap(p1,p2);
        double T=sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
        Point u=Point(sgn(p1.x-p2.x)*sqrt(sqr(p1.x-p2.x)/T),sgn(p1.y-p2.y)*sqrt(sqr(p1.y-p2.y)/T));
        double dist=dist_line(Line(p1,p2));
        double len=sqrt(R*R-dist*dist);
        double len2=sqrt(sqr(dis(p2))-sqr(dist));
        if (fabs(dis(p2+u*len2)-dist)<=eps) len+=len2;
        else len-=len2;
        Point p=p2+u*len;
        res+=S(O,p2,p);
        double ang=get_angle(p1,p);
        res+=fabs((ang/2.0)*R*R);
        return res*f;
    }
    return 0;
}
Point GetLineIntersection(Line2 a,Line2 b) {
    //直线交点
    Vector u=a.P-b.P;
    double t=Cross(b.v,u)/Cross(a.v,b.v);
    return a.P+a.v*t;
}
double DistanceToLine(Point P,Point A,Point B) {
    //点到直线的距离
    Vector v1=B-A,v2=P-A;
    return fabs(Cross(v1,v2))/Length(v1);
}
void isSegmenLineIntersection(Line2 L1,Point A,Point B,Point &ins) {
    //直线L1与线段L2是否相交
    Vector v1=L1.v;
    Vector v2=Unit(B-A);
    if(v1==v2||v1==v2*(-1)) {
        if(sgn(DistanceToLine(A,L1.P,L1.point(1.0)))!=0) return;
        else ins=A;
    } else {
        Point tmp=GetLineIntersection(L1,Line2(A,B-A));
        double ans=Dot(A-tmp,B-tmp);
        if(sgn(ans)>0) return;
        ins=tmp;
    }
}
double getarea(Point O){
    double ans=0;
    Point ins;
    for (int i=1;i<=n;i++){
        ans+=work(p[i],p[i+1],O);
        isSegmenLineIntersection(Line2(O,Point(0,1)),p[i],p[i+1],ins);
    }
    if(sgn(ans)==0) return ans=-dis(O,ins);
    return fabs(ans);
}
double ML=1e18,MR=-1e18,MU=-1e18,MD=1e18;
double sanfen(double x){
    double yL=MD,yR=MU;
    while(yR-yL>eps){
        double y1=yL+(yR-yL)/3,y2=yR-(yR-yL)/3;
        if(getarea(Point(x,y1))<getarea(Point(x,y2))) yL=y1;
        else yR=y2;
    }
    return getarea(Point(x,yL));
}
int main(){
    scanf("%d%lf",&n,&R);
    for (int i=1;i<=n;i++)//顺时针逆时针均可！！！
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
        ML=min(ML,p[i].x);
        MR=max(MR,p[i].x);
        MD=min(MD,p[i].y);
        MU=max(MU,p[i].y);
    }
    p[n+1]=p[1];
//    printf("%f\n",getarea(Point(3,3)));
    double xL=ML,xR=MR;
    while(xR-xL>eps){
        double x1=xL+(xR-xL)/3,x2=xR-(xR-xL)/3;
        if(sanfen(x1)<sanfen(x2)) xL=x1;
        else xR=x2;
    }
    printf("%.10f\n",sanfen(xL));
    return 0;
}
/*
4 1
0 0
100 10
100 12
0 1
*/

