
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct point{
    double x,y;
}point;
point ls,le,ra,rd,rb,rc;
int xs,xb,ys,yb;
double min(double x,double y){
    if(x>y)return y;
    return x;
}
double max(double x,double y){
    if(x>y)return x;
    return y;
}
int dcmp(int x){
    if(x==0)return 0;
    if(x>0)return 1;
    return -1;
}
double cross(point p0,point p1,point p2){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
double dot(double x1,double y1,double x2,double y2){
    return x1*x2+y1*y2;
}
double onseg(point a,point b,point c){
    return dcmp(dot(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y));
}
bool segcross(point a,point b,point c,point d){
    int d1,d2,d3,d4;
    d1=dcmp(cross(a,b,c));
    d2=dcmp(cross(a,b,d));
    d3=dcmp(cross(c,d,a));
    d4=dcmp(cross(c,d,b));
    if((d1^d2)==-2 && (d3^d4)==-2)return true;
    if(d1==0 && onseg(c,a,b)<=0)return true;
    if(d2==0 && onseg(d,a,b)<=0)return true;
    if(d3==0 && onseg(a,c,d)<=0)return true;
    if(d4==0 && onseg(b,c,d)<=0)return true;
    return false;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&ls.x,&ls.y,&le.x,&le.y,&ra.x,&ra.y,&rd.x,&rd.y);
        xs=min(ra.x,rd.x);xb=max(ra.x,rd.x);ys=min(ra.y,rd.y);yb=max(ra.y,rd.y);
        if(min(ls.x,le.x)>=xs && max(ls.x,le.x)<=xb && min(ls.y,le.y)>=ys && max(ls.y,le.y)<=yb){
            printf("T\n");
            continue;
        }
        ra.x=xs;ra.y=ys;
        rb.x=xs;rb.y=yb;
        rc.x=xb;rc.y=yb;
        rd.x=xb;rd.y=ys;
        if(segcross(ls,le,ra,rb) || segcross(ls,le,rb,rc) || segcross(ls,le,rc,rd) || segcross(ls,le,rd,ra)){
            printf("T\n");
        }else{
            printf("F\n");
        }
    }
    return 0;
}

