
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef long long ll;
#define maxn 110
struct Point {
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
    void in() {
        scanf("%lf%lf",&x,&y);
    }
};
typedef Point Vector;
const double eps=1e-6;
int dcmp(double x) {
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
Vector operator +(Vector A,Vector B) {
    return Vector(A.x+B.x,A.y+B.y);
}
Vector operator -(Vector A,Vector B) {
    return Vector(A.x-B.x,A.y-B.y);
}
Vector operator *(Vector A,double p) {
    return Vector(A.x*p,A.y*p);
}
Vector operator /(Vector A,double p) {
    return Vector(A.x/p,A.y/p);
}
bool operator <(const Point &a,const Point &b) {
    return dcmp(a.x-b.x)<0||(dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)<0);
}
bool operator ==(const Point &a,const Point &b) {
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
struct Line {
    Point P;
    Vector v;
    double ang;

    Line() { }  //构造函数
    Line(Point P,Vector v): P(P), v(v) { ang = atan2(v.y, v.x); }

    bool operator < (const Line& L) const { //极角排序
        return ang < L.ang;
    }

    Point point(double t) { return P + v*t; }
};
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
double Area2(Point A,Point B,Point C) {
    return Cross(B-A,C-A);
}
Vector Rotate(Vector A,double rad) { //向量旋转
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A) {
    //直线的单位法线
    double L=Length(A);
    return Vector(-A.y/L,A.x/L);
}
Vector Unit(Vector A) {
    //直线的单位向量
    double L=Length(A);
    return Vector(A.x/L,A.y/L);
}
Point GetLineIntersection(Line a,Line b) {
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
Point GetLineProjection(Point P,Point A,Point B) {
    //点在直线的投影
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}
int ConvexHull(Point *p,int n,Point *ch) {
    sort(p,p+n);
    int m = 0;
    for(int i = 0; i <n; i++) {
        while(m > 1 && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) {
        while(m > k && dcmp(Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}
Point A[maxn],B[maxn];
Vector v[maxn];
Line L[maxn];
int main() {
    freopen("roof.in","r",stdin);
    freopen("roof.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) A[i].in();
    if(Cross(A[1]-A[0],A[2]-A[0])<0)
        reverse(A,A+n);
    double ans=0;
    while(n>=3){
        double l=1e18;
        for(int i=0;i<n;i++){
            double ag=Angle(A[(i+1)%n]-A[i],A[(i-1+n)%n]-A[i]);
            v[i]=Unit(Rotate(A[(i+1)%n]-A[i],ag/2));
            L[i]=Line(A[i],v[i]);
        }
        for(int i=0;i<n;i++){
            Point C=GetLineIntersection(L[i],L[(i+1)%n]);
            l=min(l,DistanceToLine(C,A[i],A[(i+1)%n]));
        }
        int m=0;
        for(int i=0;i<n;i++){
            double ag=Angle(A[(i+1)%n]-A[i],A[(i-1+n)%n]-A[i])/2;
            double nl=l/sin(ag);
            B[m++]=A[i]+v[i]*nl;
            ans+=nl;
        }
        n=ConvexHull(B,m,A);
    }
    if(n>1) ans+=Length(A[0]-A[1]);
    printf("%.10f\n",ans);
    return 0;
}
/*
4
0 0
1 0
1 1
0 1
*/

