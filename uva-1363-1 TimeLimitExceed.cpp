
#include <stdio.h>
#define LL unsigned long long
int main(){
    int n,k,i;
    LL r;
    while(scanf("%d%d",&n,&k)!=EOF){
        r=0;
        if(n<k){
            for(i=2;i<=n;i++)r+=k%i;
            printf("%llu\n",r);
        }else{
            for(i=2;i<k;i++)r+=k%i;
            r=r+(n-k)*k;
            printf("%llu\n",r);
        }
    }
    return 0;
}

