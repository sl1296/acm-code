
#include<cstdio>
#include<cstring>
int cnt[1010];
int dp[1010][100010];
const int mod=1000000;
int main(){
    int t,a,s,b;
    while(~scanf("%d%d%d%d",&t,&a,&s,&b)){
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<a;i++){
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        for(int i=0;i<=t;i++)dp[i][0]=1;
        for(int i=1;i<=t;i++){
            for(int j=1;j<=b;j++){
                if(j-cnt[i]-1>=0){
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1-cnt[i]]+mod)%mod;
                }else{
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
                }
            }
        }
        int ans=0;
        for(int i=s;i<=b;i++)ans=(ans+dp[t][i])%mod;
        printf("%d\n",(ans+mod)%mod);
    }
    return 0;
}

