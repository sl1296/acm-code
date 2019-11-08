
#include <stdio.h>
double det(double x1,double y1,double x2,double y2){
    return x1*y2-x2*y1;
}
int main(){
    int n,m,x1,y1,x2,y2,i,u[5010],l[5010],x[5010],y[5010],c[5010],s,e,f;
    double h;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        u[0]=l[0]=x1;u[n+1]=l[n+1]=x2;
        c[0]=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&u[i],&l[i]);
            c[i]=0;
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&x[i],&y[i]);
            s=0;e=n+1;
            while(e-s>1){
                f=(s+e)/2;
                if(det(x[i]-l[f],y[i]-y2,u[f]-l[f],y1-y2)<0)e=f;else s=f;
            }
            c[s]++;
        }
        for(i=0;i<=n;i++)printf("%d: %d\n",i,c[i]);
        printf("\n");
    }
    return 0;
}

