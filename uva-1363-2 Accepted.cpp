
#include <stdio.h>
#include <math.h>
#define LL unsigned long long
int main(){
    LL n,k,i,a,b,a0,an,r;
    while(scanf("%llu%llu",&n,&k)!=EOF){
        r=0;
        if(n>k)r=r+(n-k)*k;
        a=sqrt(k);
        b=k/a;
        for(i=a;i>1;i--){
            a0=k/i;an=k/(i-1);
            if(a0>n)break;
            if(an>n)an=n;
            r=r+(k%an+k%(a0+1))*(an-a0)/2;
        }
        for(i=2;(i<=n && i<=b);i++)r+=k%i;
        printf("%llu\n",r);
    }
    return 0;
}

