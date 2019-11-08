
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
__int64 x1(__int64 a,__int64 b,__int64 c,__int64 l){
    __int64 x;
   if(a-b-c<0){
    return 0;
   }else{
    x=a-b-c>l?l:a-b-c;
    return (x+2)*(x+1)/2;
   }
}
int main(){
    __int64 a,b,c,l,n,count=0,i;
    scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&l);
    n=(l+1)*(l+2)*(l+3)/6;
    for(i=0;i<=l;i++){
        count+=x1(a+i,b,c,l-i);
        count+=x1(b+i,c,a,l-i);
        count+=x1(c+i,b,a,l-i);
    }
    printf("%I64d\n",n-count);
    return 0;
}

