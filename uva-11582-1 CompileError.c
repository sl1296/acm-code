
/*
code.c: In function 'quickpow':
code.c:7:6: error: C++ style comments are not allowed in ISO C90
      //   printf("%I64d\n",n);getchar();
      ^
code.c:7:6: error: (this will be reported only once per input file)
*/
#include <stdio.h>
#define LL unsigned long long
int f[1000100];
LL quickpow(LL m,LL n,int k){
    int b=1;
    while(n){
     //   printf("%I64d\n",n);getchar();
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
    f[1]=1;
    while(t--){
        scanf("%llu%llu%d",&a,&b,&n);
            for(i=2;;i++){
            f[i]=(f[i-1]+f[i-2])%n;
            if(f[i]==1 && !f[i-1]){
                m=i-1;
                break;
            }
        }
        //printf("%I64d %I64d %d\n",a,b,m);
        r=quickpow(a%m,b,m);
        printf("%d\n",f[r]);
    }
}

