
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
double p[25],ap[25];
int main(){
    int n,r,i,c=0,j,k;
    double l,re;
    while(1){
        c++;
        re=0;
        scanf("%d%d",&n,&r);
        if(!n && !r)break;
        for(i=0;i<n;i++)scanf("%lf",&p[i]);
        printf("Case %d:\n",c);
        if(!r){
            for(i=0;i<n;i++)printf("0.000000\n");
            continue;
        }
        memset(ap,0,sizeof(ap));
        for(i=0;i<(1<<n);i++){
            k=0;
            for(j=0;j<n;j++)if((1<<j)&i)k++;
            if(k==r){
                l=1;
                for(j=0;j<n;j++)if((1<<j)&i)l*=p[j]; else l*=(1-p[j]);
                re+=l;
                for(j=0;j<n;j++)if((1<<j)&i)ap[j]+=l;
           //     printf("%lf %lf\n",l,re);
           //     for(j=0;j<n;j++)printf("%lf %lf-- ",p[j],ap[j]);
            }
        }
        for(i=0;i<n;i++)printf("%.6lf\n",ap[i]/re);
    }
    return 0;
}

