
#include <stdio.h>
int main(){
    int c[5010],j,s,e,s2,e2,f,n,m,x1,y1,x2,y2,u[5010],l[5010],i,x[5010],y[5010];
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
            s2=s=0;e2=e=n+1;
            while(e-s>1){
                f=(s+e)/2;
                if(x[i]>u[f])s=f; else e=f;
            }
            while(e2-s2>1){
                f=(s2+e2)/2;
                if(x[i]>l[f])s2=f; else e2=f;
            }
            printf("%d %d %d %d\n",s,e,s2,e2);
            if(s2+e2==s+e){
                c[(s+e)/2]++;
                printf("c%d ",(s+e)/2);
            }else{
                if(s2+e2>s+e)e=e2; else s=s2;
                h=y1-y2;
                for(j=s+1;j<=e;j++){
                    if(u[j]+(y1-y[i])*(l[j]-u[j])/h>x[i])break;
                }
                c[j-1]++;
                printf("c%d ",j-1);
            }
        }
        for(i=0;i<=n;i++)printf("%d: %d\n",i,c[i]);
        printf("\n");
    }
    return 0;
}

