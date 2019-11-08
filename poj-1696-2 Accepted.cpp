
#include <stdio.h>
#include <math.h>
#define eps 1e-8
typedef struct point{
    int i;
    double x,y;
}point;
point a[55];
void change(int i,int j){
    point ls;
    ls.x=a[i].x;ls.y=a[i].y;ls.i=a[i].i;
    a[i].x=a[j].x;a[i].y=a[j].y;a[i].i=a[j].i;
    a[j].x=ls.x;a[j].y=ls.y;a[j].i=ls.i;
}
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
double dist(point x,point y){
    double a=x.x-y.x,b=x.y-y.y;
    return sqrt(a*a+b*b);
}
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double mulx(point both,point a,point b){
    return det(a.x-both.x,a.y-both.y,b.x-both.x,b.y-both.y);
}
int main(){
    int t,n,i,j,l;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d%lf%lf",&a[i].i,&a[i].x,&a[i].y);
            if(a[i].y<a[0].y || (a[i].y==a[0].y && a[i].x<a[0].x))change(0,i);
        }
        for(i=1;i<n;i++){
            for(j=i+1;j<n;j++){
                l=sgn(mulx(a[i-1],a[i],a[j]));
                if(l<0 || (l==0 && dist(a[i-1],a[j])<dist(a[i-1],a[i])))change(i,j);
            }
        }
        printf("%d",n);
        for(i=0;i<n;i++)printf(" %d",a[i].i);
        printf("\n");
    }
    return 0;
}

