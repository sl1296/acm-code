
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    long long n,k;
    while(1){
        scanf("%I64d%I64d",&n,&k);
        if(n==0&&k==0)break;
        long long ans=1;
        for(int i=1;i<=k;i++)ans=ans*(n-i+1)/i;
        printf("%I64d\n",ans);
    }
    return 0;
}

