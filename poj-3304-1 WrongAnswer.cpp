
#include <stdio.h>
#include <math.h>
double x[210],y[210];
int n;
int dcmp(double x){
    if(fabs(x)<1e-8)return 0;
    if(x<0)return -1;
    return 1;
}
int det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
int check(int a,int b){
    int t1,t2,i;
    for(i=0;i<n;i++){
        t1=dcmp(det(x[a]-x[b],y[a]-y[b],x[2*i+1]-x[b],y[2*i+1]-y[b]));
        t2=dcmp(det(x[a]-x[b],y[a]-y[b],x[2*i]-x[b],y[2*i]-y[b]));
        if(t1*t2==1)return 0;
    }
    return 1;
}
int main(){
    int t,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%lf%lf%lf%lf",&x[i*2],&y[i*2],&x[i*2+1],&y[i*2+1]);
        for(i=2*n-1;i>0;i--){
            for(j=i-1;j>-1;j--){
                if(dcmp(x[i]-x[j]) || dcmp(y[i]-y[j])){
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

