
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,a,b,c,d;
    while(~scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d)){
        long long k1=a-b,k2=c-d;
        long long x=k1<k2?b:d,k=min(k1,k2);
        long long xx=k1>k2?b:d,kk=max(k1,k2);
        long long cc=(n-x)/k;
        n-=cc*k;
        long long dd=(n-xx)/kk;
        printf("%lld\n",cc+dd);
    }
    return 0;
}

