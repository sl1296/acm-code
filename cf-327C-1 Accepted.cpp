
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define mod 1000000007
char s[100010];
int len;
__int64 po(__int64 a,__int64 k){
    __int64 x,ans=1;
    x=a;
    while(k){
        if(k%2)ans=(ans*x)%mod;
        x=(x*x)%mod;
        k/=2;
    }
    return ans;
}
__int64 f(__int64 n,__int64 t){
    __int64 ans,x=po(po(2,len)-1,mod-2);
    ans=(t*po(po(2,len),n)-t)%mod;
    return (ans*x)%mod;
}
int main(){
    int i,k;
    __int64 re,x;
    scanf("%s%d",s,&k);
    len=strlen(s);
    re=0;
    x=1;
    for(i=0;i<len;i++){
        if(s[i]=='0' || s[i]=='5')re=(re+x)%mod;
        x=(x*2)%mod;
    }

    printf("%I64d\n",f(k,re));
}

