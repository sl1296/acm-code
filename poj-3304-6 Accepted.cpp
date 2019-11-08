
#include<cstdio>
#include<cmath>
const double eps=1e-10;
int dcmp(double x){if(fabs(x)<eps)return 0;return x<0?-1:1;}
struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator - (Point a,Point b){return Vector(a.x-b.x,a.y-b.y);}
bool operator == (const Point& a,const Point& b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(Point pp,Point bb){p=pp;b=bb;v=b-p;}
};
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
bool opposite_side(Point p1,Point p2,Line l){
    return Cross(l.p-l.b,p1-l.b)*Cross(l.p-l.b,p2-l.b)<=eps;
}
Line x[110];
Point y[220];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            double a,b,c,d;
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            x[i]=Line(Point(a,b),Point(c,d));
            y[i*2]=Point(a,b);
            y[i*2+1]=Point(c,d);
        }
        bool ans=false;
        int en=2*n;
        for(int i=0;i<en;i++){
            for(int j=i+1;j<en;j++){
                if(y[i]==y[j])continue;
                Line tmp=Line(y[i],y[j]);
                bool pd=true;
                for(int k=0;k<n;k++){
                    if(!opposite_side(x[k].p,x[k].b,tmp)){
                        pd=false;
                        break;
                    }
                }
                if(pd){
                    ans=true;
                    break;
                }
            }
            if(ans)break;
        }
        if(ans){
            printf("Yes!\n");
        }else{
            printf("No!\n");
        }
    }
    return 0;
}

