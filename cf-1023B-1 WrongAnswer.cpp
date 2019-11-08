
#include<cstdio>
#define ll long long
int main(){
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    if(k<=n+1){
        printf("%I64d\n",k/2);
    }else if(k<=n+n-1){
        ll s=k-n-1;
        printf("%I64d\n",k/2-s);
    }else{
        printf("0\n");
    }
    return 0;
}

