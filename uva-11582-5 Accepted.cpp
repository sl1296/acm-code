
#include <stdio.h>
#define LL unsigned long long
int f[1000100];
LL quickpow(LL m,LL n,int k){
    int b=1;
    while(n){
       // printf("%d",b);
        if(n&1)b=(b*m)%k;
        n>>=1;
        m=(m*m)%k;
    }
    return b;
}
int main(){
    int t,n,m,i;
    LL a,b,r;
    scanf("%d",&t);
    f[1]=1;
    while(t--){
        scanf("%llu%llu%d",&a,&b,&n);
        if(n==1 || a==0){
            printf("0\n");
            continue;
        }
        for(i=2;i<n*n+5;i++){
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==1 && !f[i-1]){
                m=i-1;
                break;
            }
        }
        r=quickpow(a%m,b,m);
        printf("%d\n",f[r]);
    }
}

