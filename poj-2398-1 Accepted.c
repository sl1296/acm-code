
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ks{
    int o,p;
}ks;
typedef struct kt{
    int u,l;
}kt;
kt uu[5010];
ks z[5010];
int q;
int cmp(const void *a,const void *b){
    ks *aa=a,*bb=b;
    return aa->o-bb->o;
}
int cmp2(const void *a,const void *b){
    kt *aa=a,*bb=b;
    return aa->l-bb->l;
}
int main(){
    int c[5010],j,s,e,f,n,m,x1,y1,x2,y2,i,x[5010],y[5010];
    double h;
    while(1){
        q=0;
        scanf("%d",&n);
        if(!n)break;
        scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
        uu[0].u=uu[0].l=x1;uu[n+1].u=uu[n+1].l=x2;
        for(i=0;i<=n;i++)c[i]=0;
        for(i=1;i<=n;i++)scanf("%d%d",&uu[i].u,&uu[i].l);
        qsort(&uu[1],n,sizeof(kt),*cmp2);
        for(i=0;i<m;i++){
            scanf("%d%d",&x[i],&y[i]);
            s=0;e=n+1;
            while(e-s>1){
                f=(s+e)/2;
              //  printf("%d %d\n",f,(x[i]-l[f])*(y1-y2)-(u[f]-l[f])*(y[i]-y2));
                if((x[i]-uu[f].l)*(y1-y2)-(uu[f].u-uu[f].l)*(y[i]-y2)<0)e=f; else s=f;
            }
            c[s]++;
        }
        for(i=0;i<=n;i++){
          //  printf("%d ",c[i]);
            if(c[i]){
                for(j=0;j<q;j++){
                    if(c[i]==z[j].o){
                        z[j].p++;
                        break;
                    }
                }
                if(j==q){
                    z[q].o=c[i];
                    z[q].p=1;
                    q++;
                }
            }
        }
        qsort(z,q,sizeof(ks),*cmp);
        printf("Box\n");
        for(i=0;i<q;i++)printf("%d: %d\n",z[i].o,z[i].p);
    }
    return 0;
}

