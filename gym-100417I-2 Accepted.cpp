
#include<bits/stdc++.h>
using namespace std;
const double eps=1e-10;
inline int dcmp(const double& x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Point operator + (const Point& a,const Point& b){return Point(a.x+b.x,a.y+b.y);}
Point operator - (const Point& a,const Point& b){return Point(a.x-b.x,a.y-b.y);}
Point operator * (const Point& a,const double& p){return Point(a.x*p,a.y*p);}
Point operator / (const Point& a,const double& p){return Point(a.x/p,a.y/p);}
bool operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
inline double Dot(const Vector& a,const Vector& b){return a.x*b.x+a.y*b.y;}
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline double Length(const Vector& a){return sqrt(Dot(a,a));}
inline double Dis(const Point& a,const Point& b){return Length(b-a);}
inline double Angle(const Vector& a,const Vector& b){return acos(Dot(a,b)/Length(a)/Length(b));}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(const Point& pp,const Point& bb){
        p=pp;b=bb;v=b-p;
    }
};
inline Point LineInter(const Line& a,const Line& b){
    double t=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
inline double DisToLine(const Point& p,const Line& a){
    return fabs(Cross(a.v,p-a.p))/Length(a.v);
}
Point rotate(Point v,double angle){
    Point p;
    double cs=cos(angle),sn=sin(angle);
    p.x=v.x*cs-v.y*sn;
    p.y=v.x*sn+v.y*cs;
    return p;
}
Point p[110],add[110];
Line f[110];
double ar[110];
int main(){
    freopen("roof.in","r",stdin);
    freopen("roof.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%lf%lf",&p[i].x,&p[i].y);
    if(Cross(p[0]-p[1],p[2]-p[1])<0)reverse(p,p+n);
    p[n]=p[0];
    p[n+1]=p[1];
    double ans=0;
    while(1){
        for(int i=0;i<n;++i){
            ar[i]=Angle(p[i+2]-p[i+1],p[i]-p[i+1])/2;
            f[i]=Line(p[i+1],p[i+1]+rotate(p[i]-p[i+1],ar[i]));
        }
        f[n]=f[0];
        double mi=1e100;
        for(int i=0;i<n;++i){
            double dis=DisToLine(LineInter(f[i],f[i+1]),Line(p[i],p[i+1]));
            if(dcmp(dis-mi)<0)mi=dis;
        }
        int an=n;
        for(int i=0;i<n;++i){
            ans+=mi/sin(ar[i]);
            add[i]=p[i+1]+f[i].v/Length(f[i].v)*(mi/sin(ar[i]));
        }
        an=unique(add,add+n)-add;
        for(int i=0;i<an;++i)p[i]=add[i];
        n=an;
        if(p[n-1]==p[0])--n;
        if(n<=1)break;
        if(n==2){
            ans+=Dis(p[0],p[1]);
            break;
        }
        p[n]=p[0];
        p[n+1]=p[1];
    }
    printf("%.10f\n",ans);
    return 0;
}

