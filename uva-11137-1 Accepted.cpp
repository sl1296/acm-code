
#include<cstdio>
#define ll long long
ll dp[10010]={1};
int main(){
    for(int i=1;i<22;i++){
        int tmp=i*i*i;
        for(int j=0;j<10005-tmp;j++)dp[tmp+j]+=dp[j];
    }
    int n;
    while(~scanf("%d",&n))printf("%lld\n",dp[n]);
    return 0;
}

