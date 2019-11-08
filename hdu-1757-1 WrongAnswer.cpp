
#include <stdio.h>
int f[300100];
int main(){
    int k,m,a[11],zt,x,i,j;
    while(scanf("%d%d",&k,&m)!=EOF){
        for(i=0;i<10;i++){
            scanf("%d",&a[i]);
            f[i]=i%m;
        }
        for(;i<m*3;i++){
            f[i]=0;
            for(j=0;j<10;j++)f[i]+=a[j]*f[i-j-1];
            f[i]%=m;
            if(i>30){
                for(j=0;j<10;j++)if(f[i-j]!=f[30-j])break;
                if(j==10)break;
            }
            if(i==k)break;
        }
        zt=i-30;
        if(k<=i)printf("%d\n",f[k]);
        else{
            x=k-(k-20)/zt*zt;
            printf("%d\n",f[x]);
        }
    }
    return 0;
}

