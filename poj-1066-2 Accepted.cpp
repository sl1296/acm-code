
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps (1e-8)
int min;
typedef struct point{
    double x,y;
}point;
point p[65],t;
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double mulx(point a,point b,point both){
    return det(a.x-both.x,a.y-both.y,b.x-both.x,b.y-both.y);
}
bool cross2(point la,point lb,point x,point y){
    if(mulx(la,x,lb)*mulx(la,y,lb)<-eps)return true;
    return false;
}
int main(){
    int n,i,j,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&p[i*2].x,&p[i*2].y,&p[i*2+1].x,&p[i*2+1].y);
    scanf("%lf%lf",&t.x,&t.y);
    min=1e9;
    for(i=0;i<n*2;i++){
        c=0;
        for(j=0;j<n;j++)if(cross2(p[j*2],p[j*2+1],p[i],t))c++;
        if(c<min)min=c;
    }
    if(!n)min=0;
    min++;
    printf("Number of doors = %d\n",min);
}

