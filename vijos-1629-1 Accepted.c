
#include <stdio.h>
__int64 n,a[16],x,y,m;
__int64 gcd(__int64 a,__int64 b){
    __int64 r;
    while(b){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
__int64 ca(__int64 t){
    __int64 i,r,c,l,j;
    r=t/8;
    for(i=1;i<m;i++){
        c=0;
        l=8;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                l=l*a[j]/gcd(l,a[j]);
                c++;
            }
        }
        if(c&1)r-=t/l; else r+=t/l;
    }
    return r;
}
int main(){
    __int64 i;
    scanf("%I64d",&n);m=1<<n;
    for(i=0;i<n;i++)scanf("%I64d",&a[i]);
    scanf("%I64d%I64d",&x,&y);
    printf("%I64d\n",ca(y)-ca(x-1));
    return 0;
}

