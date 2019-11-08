
#include <stdio.h>
#define LL unsigned long long
int f[1000100];
LL quickpow(LL m,LL n,int k){
    int b=1;
    while(n){
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
    while(t--){
        scanf("%llu%llu%d",&a,&b,&n);
        f[1]=1%n;
        for(i=2;;i++){
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==f[1] && f[i-1]==f[0]){
                m=i-1;
                break;
            }
        }
        r=quickpow(a%m,b,m);
        printf("%d\n",f[r]);
    }
    return 0;
}

