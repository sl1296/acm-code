
#include<cstdio>
#include<cmath>
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
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
bool isLine(Vector a,Vector b){return dcmp(Cross(a,b))==0;}
struct Line{
    Point p,b;
    Vector v;
    Line(){}
    Line(Point pp,Point bb){p=pp;b=bb;v=b-p;}
};
Point LineInter(Line a,Line b){
    double t=Cross(b.v,a.p-b.p)/Cross(a.v,b.v);
    return a.p+a.v*t;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        printf("INTERSECTING LINES OUTPUT\n");
        for(int i=0;i<n;i++){
            int a,b,c,d,e,f,g,h;
            scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g,&h);
            Line t1=Line(Point(a,b),Point(c,d)),t2=Line(Point(e,f),Point(g,h));
            if(isLine(t1.v,t2.v)){
                if(isLine(t1.v,t2.p-t1.p)){
                    printf("LINE\n");
                }else{
                    printf("NONE\n");
                }
            }else{
                Point in=LineInter(t1,t2);
                printf("POINT %.2f %.2f\n",in.x,in.y);
            }
        }
    }
    return 0;
}

