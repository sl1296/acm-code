
#include <stdio.h>
int main(){
    long long n,r,l,ln;
    long long i,c=1,zsn;
    while(1){
        scanf("%lld",&n);
        if(!n)break;
        zsn=r=0;
        ln=n;
        for(i=2;i*i<=n;i++){
       //     printf("%d ",i);
            if(n%i==0){
                l=i;
                n/=i;
                while(n%i==0){
                    n/=i;
                    l*=i;
                }
                zsn++;
                r+=l;
                if(n==1)break;
            }
        }
        if(n>1){
            r+=n;
        //printf("%lld",r);
            zsn++;
        }
        if(zsn<2)r++;
        if(ln==1)r=2;
        printf("Case %lld: %lld\n",c,r);
        c++;
    }
    return 0;
}

