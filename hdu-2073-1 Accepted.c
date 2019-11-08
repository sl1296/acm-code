
#include <stdio.h>
#include <math.h>
int main(){
    int n,i,j,k,l,t,u,x1,x2,y1,y2,z;
    int x[21000],y[21000];
    double d[21000],re;
    k=0;
    for(i=1;i<203;i++){
        for(j=0;j<i;j++){
            y[k]=i-1-j;
            x[k]=j;
            k++;
        }
    }
    for(i=0;i<20150;i++){
        d[i]=sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
  //     printf("%f,",d[i]);getchar();
    }
    scanf("%d",&n);
    for(z=0;z<n;z++){
        re=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        for(i=0;i<20150;i++){
            if(x1==x[i] && y1==y[i]){
                t=i;
                break;
            }
        }
        for(i=0;i<20150;i++){
            if(x2==x[i] && y2==y[i]){
                u=i;
                break;
            }
        }
        if(t>u){
            l=t;
            t=u;
            u=l;
        }
   //     printf("%d %d ",t,u);
        for(i=t;i<u;i++){
            re+=d[i];
        }
        printf("%.3f\n",re);
    }
    return 0;
}

