
#include <stdio.h>
int c;
typedef struct point{
    double x,y;
}point;
point p1[100100],p2[100100];
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
double mulx(point a,point b,point both){
    return det(a.x-both.x,a.y-both.y,b.x-both.x,b.y-both.y);
}
int main(){
    int n,i,j;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        c=0;
        printf("Top sticks: ");
        for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&p1[i].x,&p1[i].y,&p2[i].x,&p2[i].y);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++)if(mulx(p1[i],p1[j],p2[i])*mulx(p1[i],p2[j],p2[i])<0 && mulx(p1[j],p1[i],p2[j])*mulx(p1[j],p2[i],p2[j])<0)break;
            if(j==n){
                if(c)printf(", ");
                printf("%d",i+1);
                c++;
            }
        }
        printf(".\n");
    }
}

