
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
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
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(const Point& pp,const Point& bb){
        p=pp;b=bb;v=b-p;
    }
    double getx(const double& y){
        return (p+v*((y-p.y)/v.y)).x;
    }
    double gety(const double& x){
        return (p+v*((x-p.x)/v.x)).y;
    }
};
struct node{
	double l,r;
	bool operator < (const node &p) const{
		if(dcmp(l-p.l))return l<p.l;
		return r<p.r;
	}
};
node in[100000];
int main(){
	while(1){
		int cc=0;
		double a,b,c,d,e,f;
		scanf("%lf%lf%lf",&a,&b,&c);
		if(!dcmp(a)&&!dcmp(b)&&!dcmp(c))break;
		scanf("%lf%lf%lf",&d,&e,&f);
		Line hh=Line(Point(a,c),Point(b,c)),rr=Line(Point(d,f),Point(e,f));
		in[cc++]=(node){d,d};in[cc++]=(node){e,e};
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&a,&b,&c);
			if(dcmp(c-hh.p.y)==0)continue;
			if(dcmp((c-hh.p.y)*(c-rr.p.y))>0)continue;
			Line x1=Line(Point(a,c),hh.b);
			Line x2=Line(Point(b,c),hh.p);
			double s1=x1.getx(rr.p.y),s2=x2.getx(rr.p.y);
			s1=max(s1,d);s2=min(s2,e);
			if(dcmp(s1-s2)<0)in[cc++]=(node){s1,s2};
		}
		sort(in,in+cc);
		double pf=d,pt=d,ans=0;
		for(int i=1;i<cc;i++){
			if(dcmp(in[i].l-pt)<=0)pt=max(pt,in[i].r);
			else{
				ans=max(ans,in[i].l-pt);
				pf=in[i].l;
				pt=in[i].r;
			}
		}
		if(dcmp(ans)){
			printf("%.2f\n",ans);
		}else{
			printf("No View\n");
		}
	}
	return 0;
}

