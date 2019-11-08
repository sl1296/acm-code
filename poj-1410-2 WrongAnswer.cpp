
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define eps (1e-8)
typedef struct point{
    double x,y;
}point;
point ls,le,ra,rd,rb,rc;
double mult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cross(point a,point b,point x,point y){
    if(mult(a,x,b)*mult(a,y,b)<=eps)return true;
    return false;
}
bool judge(point a,point b,point x,point y){
    if(cross(a,b,x,y) && cross(x,y,a,b))return false;
    return true;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ls.x,&ls.y,&le.x,&le.y,&ra.x,&ra.y,&rd.x,&rd.y);
        rb.x=ra.x;rb.y=rd.y;rc.x=rd.x;rc.y=ra.y;
        if(judge(ra,rb,ls,le) && judge(ra,rc,ls,le) && judge(rb,rd,ls,le) && judge(rc,rd,ls,le))
            printf("F\n");
        else printf("T\n");
    }
    return 0;
}

