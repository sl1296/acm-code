
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 200010
struct Point {
    double x,y;
    Point(double x=0,double y=0):x(x),y(y) {}
    void in() {
        scanf("%lf%lf",&x,&y);
    }
};
typedef Point Vector;
struct Circle {
    Point c;
    double r;
    Circle(Point c=(Point) {
        0,0
    },double r=0):c(c),r(r) {}
    Point point(double a) {
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
    void in() {
        c.in();
        scanf("%lf",&r);
    }
};
const double eps=1e-6;
const double PI=acos(-1);
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
struct node{
    double ag;
    int v;
    bool operator <(const node &rhs)const{
        return dcmp(ag-rhs.ag)<0||dcmp(ag-rhs.ag)==0&&v>rhs.v;
    }
}a[maxn];
int len;
void getTangents(Point p,Circle C) {
    //点在圆上的切线
    Vector u=C.c-p;
    double dist=Length(u);
    double ang=asin(C.r/dist);
    Vector v=Rotate(u,-ang);
    a[len++]=(node){atan2(v.y,v.x),1};
    if(dcmp(a[len-1].ag)==0) a[len-1].ag=0;
    if(a[len-1].ag<0) a[len-1].ag+=2*PI;
    v=Rotate(u,ang);
    a[len++]=(node){atan2(-v.y,-v.x),-1};
    if(dcmp(a[len-1].ag)==0) a[len-1].ag=0;
    if(a[len-1].ag<0) a[len-1].ag+=2*PI;
}
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int n;
        len=0;
        Circle C;
        Point P;
        scanf("%d%lf",&n,&C.r);
        C.c.x=C.c.y=0;
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&P.x,&P.y);
            if(dcmp(Length(P)-C.r)<=0) cnt++;
            else getTangents(P,C);
            if(dcmp(P.y+C.r)>=0&&dcmp(Length(P)-C.r)>0){
                ans++;
            }
        }
        int ns=ans;
        sort(a,a+len);
        for(int i=0;i<len;i++){
            if(dcmp(a[i].ag)==0&&a[i].v==1) continue;
//            printf("%d : %f %d\n",i,a[i].ag,a[i].v);
            ns+=a[i].v;
            ans=max(ans,ns);
        }
        printf("%d\n",ans+cnt);
    }
    return 0;
}
/*
1
5 1
0 1
1 -1
-1 1
1 1
-1 -1
*/

