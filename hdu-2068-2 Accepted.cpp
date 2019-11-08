
#include <stdio.h>
#define ll __int64
ll a[20];
ll c(ll n,ll k){
    ll i,r=1;
    for(i=1;i<=k;i++)r=r*(n-i+1)/i;
    return r;
}
int main(){
    ll n,i,l,re;
    a[0]=a[2]=1;
    for(i=3;i<14;i++)a[i]=(i-1)*(a[i-1]+a[i-2]);
    while(1){
        scanf("%I64d",&n);
        if(!n)break;
        l=(n+1)/2;
        re=0;
        for(i=l;i<=n;i++)re=re+c(n,i)*a[n-i];
        printf("%I64d\n",re);
    }
    return 0;
}

