
#include<cstdio>
#include<cmath>
#include<vector>
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
int dots_inline(Point p1,Point p2,Point p3){
    return dcmp(Cross(p1-p3,p2-p3))==0;
}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(Point pp,Point bb){p=pp;b=bb;v=b-p;}
};
bool same_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)>eps;
}
bool dot_online_in(Point p,Line l){
    return dcmp(Cross(p-l.b,l.p-l.b))==0&&(l.p.x-p.x)*(l.b.x-p.x)<eps&&(l.p.y-p.y)*(l.b.y-p.y)<eps;
}
bool intersect_in(Line u,Line v){
    if(!dots_inline(u.p,u.b,v.p)||!dots_inline(u.p,u.b,v.b))
        return!same_side(u.p,u.b,v)&&!same_side(v.p,v.b,u);
    return dot_online_in(u.p,v)||dot_online_in(u.b,v)||dot_online_in(v.p,u)||dot_online_in(v.b,u);
}
struct node{
    Line x;
    int id;
};
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        vector<node> ve;
        for(int i=0;i<n;i++){
            double a,b,c,d;
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            Line add=Line(Point(a,b),Point(c,d));
            int sz=ve.size();
            for(int j=sz-1;j>=0;j--){
                if(intersect_in(add,ve[j].x))ve.erase(ve.begin()+j);
            }
            ve.push_back((node){add,i+1});
        }
        int sz=ve.size();
        printf("Top sticks: ");
        for(int i=0;i<sz;i++){
            printf("%d",ve[i].id);
            if(i==sz-1)printf(".\n");else printf(", ");
        }
    }
}

