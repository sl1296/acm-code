
#include <stdio.h>
#include <string.h>
#include <Stdlib.h>
#include <math.h>
__int64 gcd(__int64 a,__int64 b){
    __int64 r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main(){
    __int64 n,a,b,p,q,r,s,u;
    scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&p,&q);
    r=n/a;
    s=n/b;
    u=a*b/gcd(a,b);
    u=n/u;
    if(p>q){
        printf("%I64d\n",p*r+q*(s-u));
    }else{
        printf("%I64d\n",q*s+p*(r-u));
    }
    return 0;
}

