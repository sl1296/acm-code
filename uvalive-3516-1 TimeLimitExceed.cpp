
#include<cstdio>
#include<cstring>
#define ll long long
const ll mod=1000000000;
char s[310];
ll dp[310][310];
ll dfs(int i,int j){
    if(i==j)return 1;
    if(s[i]!=s[j])return 0;
    ll ans=dp[i][j];
    if(ans>=0)return ans;
    ans=0;
    for(int k=i+2;k<=j;k++)ans=(ans+dfs(i+1,k-1)*dfs(k,j)%mod)%mod;
    return ans;
}
int main(){
    while(~scanf("%s",s)){
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",dfs(0,strlen(s)-1));
    }
    return 0;
}

