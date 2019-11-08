
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
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
    double getx(double y){
        return (p+v*((y-p.y)/v.y)).x;
    }
    double gety(double x){
        return (p+v*((x-p.x)/v.x)).y;
    }
};
bool opposite_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)<=eps;
}
Point LineInter(Line a,Line b){
    double t=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
Point p[25],q[25],all[50];
Line lp[50],lq[25];
struct node{
    Point p;
    int id;
};
bool cmp(node a,node b){
    return a.p.x<b.p.x;
}
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        int cnt=0;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&p[i].x,&p[i].y);
            q[i]=p[i];
            q[i].y-=1.0;
            all[cnt++]=p[i];
            all[cnt++]=q[i];
            if(i){
                lp[i]=Line(p[i-1],p[i]);
                lq[i]=Line(q[i-1],q[i]);
            }
        }
        double ans=p[0].x;
        for(int i=0;i<cnt;i++){
            for(int j=i+1;j<cnt;j++){
                if(dcmp(all[i].x-all[j].x)){
                    Line now=Line(all[i],all[j]);
                    double y=now.gety(p[0].x);
                    if(dcmp(p[0].y-y)>=0&&dcmp(y-q[0].y)>=0){
//                        printf("i=%d j=%d\n",i,j);
//                        printf("%f %f %f %f\n",now.p.x,now.p.y,now.b.x,now.b.y);
                        vector<node> ve;
                        for(int i=1;i<n;i++){
                            ve.push_back((node){p[i],i});
                            if(opposite_side(p[i-1],p[i],now)&&!isLine(lp[i].v,now.v)){
                                ve.push_back((node){LineInter(lp[i],now),i});
                            }
                            if(opposite_side(q[i-1],q[i],now)&&!isLine(lq[i].v,now.v)){
                                ve.push_back((node){LineInter(lq[i],now),i});
                            }
                        }
                        int sz=ve.size();
//                        printf("sz=%d\n",sz);
                        sort(ve.begin(),ve.end(),cmp);
                        double tmp=p[0].x;
                        for(int i=0;i<sz;i++){
//                            printf("x=%f y=%f id=%d\n",ve[i].p.x,ve[i].p.y,ve[i].id);
                            double uu=lp[ve[i].id].gety(ve[i].p.x);
                            double xx=now.gety(ve[i].p.x);
                            double dd=lq[ve[i].id].gety(ve[i].p.x);
//                            printf("%f %f %f\n",uu,xx,dd);
                            if(dcmp(uu-xx)>=0&&dcmp(xx-dd)>=0)tmp=ve[i].p.x;
                            else break;
                        }
//                        printf("    tmp=%f\n",tmp);
                        ans=max(ans,tmp);
                    }
                }
            }
        }
        if(dcmp(ans-p[n-1].x)==0){
            printf("Through all the pipe.\n");
        }else{
            printf("%.2f\n",ans);
        }
    }
    return 0;
}

