
#include<cstdio>
long long dp[500];
int main(){
    int n,d;
    while(~scanf("%d%d",&n,&d)){
        if(n<=1){
            printf("0\n");
            continue;
        }
        if(n==2){
            if(d<=0){
                printf("0\n");
            }else{
                printf("1\n");
            }
            continue;
        }
        long long left=(1LL<<(n-1))-1;
        for(int i=0;i<=d;++i)dp[i]=i;
        for(int i=d+1;i<=n-d-2;++i)dp[i]=dp[i-1]+2+dp[i-d-1];
        long long right=0;
        if(n-d-2>=0)right=dp[n-d-2]+1;
        printf("%lld\n",left-right);
    }
    return 0;
}

