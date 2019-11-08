
#include <stdio.h>
#include <math.h>
__int64 p,k;
__int64 po(__int64 m,__int64 n){
    __int64 b=1;
    while(n){
       // printf("%I64d ",b);
        if(n&1)b=(b*m)%1000000007;
        n>>=1;
        m=(m*m)%1000000007;
    }
    return b;
}
int main(){
    __int64 l,i,x;
    scanf("%I64d%I64d",&p,&k);
    if(k==0){
        printf("%I64d\n",po(p,p-1));
    }else if(k==1){
        printf("%I64d\n",po(p,p));
    }else{
        l=k;
        for(i=1;i<p;i++){
            if(l==1)break;
            l*=k;
            l%=p;
        }
        x=ceil((p-1)/(double)i);
     //   printf("%I64d ",x);
        printf("%I64d\n",po(p,x));
    }
    return 0;
}

