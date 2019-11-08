
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int c[5010],j,s,e,f,n,m,x1,y1,x2,y2,u[5010],l[5010],i,x[5010],y[5010];
    double h;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        u[0]=l[0]=x1;u[n+1]=l[n+1]=x2;
        for(i=0;i<=n;i++)c[i]=0;
        for(i=1;i<=n;i++)scanf("%d%d",&u[i],&l[i]);
        for(i=0;i<m;i++){
            scanf("%d%d",&x[i],&y[i]);
            s=0;e=n+1;
            while(e-s>1){
                f=(s+e)/2;
              //  printf("%d %d\n",f,(x[i]-l[f])*(y1-y2)-(u[f]-l[f])*(y[i]-y2));
                if((x[i]-l[f])*(y1-y2)-(u[f]-l[f])*(y[i]-y2)<0)e=f; else s=f;
            }
            c[s]++;
        }
        for(i=0;i<=n;i++)printf("%d: %d\n",i,c[i]);
        printf("\n");
    }
    return 0;
}

