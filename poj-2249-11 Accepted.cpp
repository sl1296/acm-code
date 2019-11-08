
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0&&k==0)break;
        if(n-k<k)k=n-k;
        long long ans=1;
        for(int i=1;i<=k;i++)ans=ans*(n-i+1)/i;
        printf("%I64d\n",ans);
    }
    return 0;
}

