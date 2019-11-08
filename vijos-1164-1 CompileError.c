
#include <stdio.h>
__int64 n,a[12],b[12];
/*__int64*/void gcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if (b==0){
        x=1,y=0;
        return;
        //return a;
    }
    /*__int64 q=*/gcd(b,a%b,y,x);
    y-=a/b*x;
  //  return q;
}
__int64 h(){
    __int64 i,m,e=1,sum=0,x,y;
    for(i=0;i<n;i++)e*=a[i];
    for(i=0;i<n;i++){
        m=e/a[i];
        gcd(m,a[i],x,y);
        sum=(sum+x*m*b[i])%e;
    }
    m=(sum+e)%e;
    for(i=0;i<n;i++)if(m<a[i])m+=e;
    return m;
}
int main(){
    __int64 i;
    scanf("%I64d",&n);
    for(i=0;i<n;i++)scanf("%I64d%I64d",&a[i],&b[i]);
    printf("%I64d\n",h());
    return 0;
}

