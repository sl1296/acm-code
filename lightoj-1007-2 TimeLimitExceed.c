
#include <stdio.h>
int re[5000005],is[5000005];
int z[500000]={2,3,5,7,11},zc=5;
int f(int x){
    int r=1,i;
    for(i=0;x>1;i++){
        if(x%z[i]==0){
            x/=z[i];
            r*=(z[i]-1);
            while(x%z[i]==0){
                x/=z[i];
                r*=z[i];
            }
            //printf("%d %d %d",r,z[i],x);
        }
    }
    return r;
}
int main(){
    int t,i,a,b,c,j,d;
    for(i=13;i<5000001;i++){
        for(j=0;z[j]*z[j]<=i;j++){
            if(i%z[j]==0)break;
        }
        if(z[j]*z[j]>i){
            z[zc]=i;
            zc++;
        }
    }
    scanf("%d",&t);
    for(i=0;i<t;i++){
        c=0;
        scanf("%d%d",&a,&b);
        for(j=a;j<=b;j++){
            if(is[j]){
                c+=re[j];
            }else{
                d=f(j);
                re[j]=d*d;
                is[j]=1;
                c=c+re[j];
            }
        }
        printf("Case %d: %d\n",i+1,c);
    }
    return 0;
}

