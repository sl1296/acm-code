
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
    __int64 a,b,c,d,n,r;
    int k,l;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d)!=EOF){
        k=a-d;
        l=b-c;
        r=n*(n-abs(k)-abs(l));
        if(r<0)r=0;
        printf("%I64d\n",r);
    }
    return 0;
}

