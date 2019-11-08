
#include<cstdio>
#define ll long long
ll dp[110][2];
int main(){
    int l,k;
    scanf("%d%d",&l,&k);
    dp[0][1]=1;
    ll ans=0;
    for(int i=1;i<=l;++i){
        dp[i][0]+=dp[i-1][1];
        if(i-k>=0)dp[i][0]+=dp[i-k][1];
        dp[i][1]+=dp[i-1][0];
        ans+=dp[i][0];
    }
    printf("%lld\n",ans);
    return 0;
}

