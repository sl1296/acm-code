
#include <stdio.h>
#define ll __int64
ll f[100];
int main(){
    int i,t;
    ll n;
    f[1]=f[0]=1;
    for(i=2;i<90;i++)f[i]=f[i-1]+f[i-2];
    for(i=2;i<90;i++)f[i]+=f[i-1];
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        for(i=89;i>0;i--)if(n>=f[i])break;
        printf("%d\n",i);
    }
    return 0;
}

