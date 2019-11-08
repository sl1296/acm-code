
#include <stdio.h>
int c;
typedef struct point{
    double x,y;
}point;
double mult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);
}
point p1[100100],p2[100100];
int main(){
    int n,i,j;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        c=0;
        printf("Top sticks: ");
        for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&p1[i].x,&p1[i].y,&p2[i].x,&p2[i].y);
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++)if(mult(p1[i],p1[j],p2[i])*mult(p1[i],p2[j],p2[i])<0 && mult(p1[j],p1[i],p2[j])*mult(p1[j],p2[i],p2[j])<0)break;
            if(j==n){
                if(c)printf(", ");
                printf("%d",i+1);
                c++;
            }
        }
        printf(".\n");
    }
}

