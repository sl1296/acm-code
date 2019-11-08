
#include <stdio.h>
#include <math.h>
#define eps 1e-8
typedef struct point{
    double x,y;
}point;
point a[210];
int n;
int sgn(double x){
    if(fabs(x)<eps)return 0;
    if(x<0)return -1;
    return 1;
}
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double mulx(point both,point a,point b){
    return det(a.x-both.x,a.y-both.y,b.x-both.x,b.y-both.y);
}
int check(int x,int y){
    int t1,t2,i;
    for(i=0;i<n;i++){
        t1=sgn(mulx(a[y],a[x],a[2*i+1]));
        t2=sgn(mulx(a[y],a[x],a[2*i]));
        if(t1*t2==1)return 0;
    }
    return 1;
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&a[i*2].x,&a[i*2].y,&a[i*2+1].x,&a[i*2+1].y);
        for(i=2*n-1;i>0;i--){
            for(j=i-1;j>-1;j--){
                if(sgn(a[i].x-a[j].x) || sgn(a[i].y-a[j].y)){
                    if(check(i,j)){
                        printf("Yes!\n");
                        goto a;
                    }
                }
            }
        }
        printf("No!\n");
        a:;
    }
    return 0;
}

