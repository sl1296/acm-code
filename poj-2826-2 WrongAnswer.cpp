
#include <stdio.h>
#include <math.h>
#define eps 1e-8
typedef struct point{
    double x,y;
}point;
point s1,e1,s2,e2,c;
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double mulx(point both,point a,point b){
    return det(a.x-both.x,a.y-both.y,b.x-both.x,b.y-both.y);
}
bool cross(point la,point lb,point x,point y){
    if(mulx(la,x,lb)*mulx(la,y,lb)>eps)return false;
    return true;
}
int main(){
    int t;
    double a1,b1,c1,a2,b2,c2,s;
    scanf("%d",&t);
    while(t--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&s1.x,&s1.y,&e1.x,&e1.y,&s2.x,&s2.y,&e2.x,&e2.y);
        if(s1.y==e1.y || s2.y==e2.y || det(e1.x-s1.x,e1.y-s1.y,e2.x-s2.x,e2.y-s2.y)==0){
            printf("0.00\n");
            continue;
        }
        if(!cross(s1,e1,s2,e2) || !cross(s1,e1,s2,e2)){
            printf("0.00\n");
            continue;
        }
        a1=s1.y-e1.y;
        b1=e1.x-s1.x;
        c1=s1.x*e1.y-e1.x*s1.y;
        a2=s2.y-e2.y;
        b2=e2.x-s2.x;
        c2=s2.x*e2.y-e2.x*s2.y;
        c.x=(c1*b2-c2*b1)/(a2*b1-a1*b2);
        c.y=(a2*c1-a1*c2)/(a1*b2-a2*b1);
        if(s1.y>e1.y){
            e1.y=s1.y;e1.x=s1.x;
        }
        if(s2.y>e2.y){
            e2.y=s2.y;e2.x=s2.x;
        }
        if(e1.y<e2.y)e2.y=e1.y; else e1.y=e2.y;
        s=fabs(e2.x-e1.x)*(e2.y-c.y)/2;
        printf("%.2f\n",s);
    }
    return 0;
}

