
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-10;
const double inf=1e10;
double w;
struct point{
    double x,y;
    point(double x,double y):x(x),y(y){}
    point operator - (const point &p) const{
        return point(x-p.x,y-p.y);
    }
    double sqr(){
        return x*x+y*y;
    }
    double len(){
        return sqrt(x*x+y*y);
    }
    double arg(){
        return atan2(y,x);
    }
    point rot(double a){
        return point(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a));
    }
};
inline int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
inline double cal(point a,point b){
    if(sgn(a.len()-w)<=0){
        b=b.rot(-a.arg());
        if(b.x>=-eps&&b.x<=w+eps&&b.y>=-eps)return b.y;
    }else{
        double h=sqrt(a.sqr()-w*w);
        double x=atan(h/w);
        b=b.rot(x-a.arg());
        if(b.x>=-eps&&b.x<=w+eps&&b.y>=-eps)return max(b.y,h);
    }
    return inf;
}
int main(){
//    freopen("b.in","r",stdin);
//    freopen("b.out","w",stdout);
    int t;
    scanf("%d",&t);
    double a,b,c,d,e,f;
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f,&w);
        point pa=point(a,b),pb=point(c,d),pc=point(e,f);
        double ans=inf;
        ans=min(ans,cal(pa-pc,pb-pc));
        ans=min(ans,cal(pb-pc,pa-pc));
        ans=min(ans,cal(pc-pb,pa-pb));
        ans=min(ans,cal(pa-pb,pc-pb));
        ans=min(ans,cal(pc-pa,pb-pa));
        ans=min(ans,cal(pb-pa,pc-pa));
        pa.x=-pa.x;pb.x=-pb.x;pc.x=-pc.x;
        ans=min(ans,cal(pa-pc,pb-pc));
        ans=min(ans,cal(pb-pc,pa-pc));
        ans=min(ans,cal(pc-pb,pa-pb));
        ans=min(ans,cal(pa-pb,pc-pb));
        ans=min(ans,cal(pc-pa,pb-pa));
        ans=min(ans,cal(pb-pa,pc-pa));
        if(sgn(ans-inf)==0)printf("impossible\n");
        else printf("%.9f\n",ans);
    }
    return 0;
}

