
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
        }
        bool ans=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                Line tmp[4]={
                    Line(x[i].p,x[j].p),
                    Line(x[i].p,x[j].b),
                    Line(x[i].b,x[j].p),
                    Line(x[i].b,x[j].b)
                };
                for(int k=0;k<4;k++){
                    bool pd=true;
                    for(int l=0;l<n;l++){
                        if(!opposite_side(x[l].p,x[l].b,tmp[k])){
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

