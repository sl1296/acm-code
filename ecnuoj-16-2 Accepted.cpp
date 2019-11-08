
#include<bits/stdc++.h>
using namespace std;
bool sx[1000010];
int num[1000010];
int main(){
    for(long long i=2;i<1000005;i++){
        if(!sx[i]){
            for(long long j=i*i;j<1000005;j+=i){
                sx[j]=true;
            }
        }
    }
    for(int i=2;i<1000005;i++){
        num[i]=num[i-1];
        if(!sx[i])++num[i];
    }
    num[1]=num[0]=1;
    long long k,n;
    while(~scanf("%lld%lld",&k,&n)){
        long long now=num[n],pre;
        for(int i=2;i<=k;i++){
            pre=now;
            now=num[now];
            if(now==pre)break;
        }
        printf("%lld\n",now);
    }
    return 0;
}

