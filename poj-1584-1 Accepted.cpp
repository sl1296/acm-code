
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
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
inline double Cross(const Vector& a,const Vector& b){return a.x*b.y-a.y*b.x;}
inline double Dot(const Vector& a,const Vector& b){return a.x*b.x+a.y*b.y;}
inline double Length(const Vector& a){return sqrt(Dot(a,a));}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(const Point& pp,const Point& bb){
        p=pp;b=bb;v=b-p;
    }
};
inline int dots_inline(const Point& p1,const Point& p2,const Point& p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
inline bool dot_online_in(const Point& p,const Line& l){
    return dcmp(Cross(p-l.b,l.p-l.b))==0&&(l.p.x-p.x)*(l.b.x-p.x)<eps&&(l.p.y-p.y)*(l.b.y-p.y)<eps;
}
inline double DisToLine(const Point& p,const Line& a){
    return fabs(Cross(a.v,p-a.p))/Length(a.v);
}
typedef vector<Point> Polygon;
inline int isPointInPloygon(const Point& p,const Polygon& poly){
    int wn=0;
    int n=poly.size();
    for(int i=0;i<n;i++){
        if(dot_online_in(p,Line(poly[i],poly[(i+1)%n])))return -1;
        int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0)wn++;
        if(k<0&&d2<=0&&d1>0)wn--;
    }
    if(wn!=0)return 1;
    return 0;
}
vector<Point> ve;
int main(){
    int n;
    while(1){
        ve.clear();
        scanf("%d",&n);
        if(n<3)break;
        double r;
        Point p;
        scanf("%lf%lf%lf",&r,&p.x,&p.y);
        for(int i=0;i<n;i++){
            Point tmp;
            scanf("%lf%lf",&tmp.x,&tmp.y);
            ve.push_back(tmp);
        }
        bool pd1=true;
        bool pd2=true;
        for(int i=0;i<n;i++){
            int now=dcmp(Cross(ve[(i+1)%n]-ve[i%n],ve[(i+2)%n]-ve[(i+1)%n]));
            if(now==-1){
                pd1=false;
            }else if(now==1){
                pd2=false;
            }
        }
        if(pd1||pd2){
            bool in=true;
            if(isPointInPloygon(p,ve)){
                for(int i=0;i<n;i++){
                    Line now=Line(ve[i],ve[(i+1)%n]);
                    if(dcmp(DisToLine(p,now)-r)<0){
                        in=false;
                        break;
                    }
                }
            }else{
                in=false;
            }
            if(in){
                printf("PEG WILL FIT\n");
            }else{
                printf("PEG WILL NOT FIT\n");
            }
        }else{
            printf("HOLE IS ILL-FORMED\n");
        }
    }
    return 0;
}

