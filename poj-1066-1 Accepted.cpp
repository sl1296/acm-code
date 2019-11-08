
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define eps (1e-8)
int min;
typedef struct point{
    double x,y;
}point;
point p[65],t;
double mult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
bool cross(point la,point lb,point x,point y){
    if(mult(la,x,lb)*mult(la,y,lb)<-eps)return true;
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
        for(j=0;j<n;j++)if(cross(p[j*2],p[j*2+1],p[i],t))c++;
        if(c<min)min=c;
    }
    if(!n)min=0;
    min++;
    printf("Number of doors = %d\n",min);
}

