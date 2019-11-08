
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;
LL mod=1000000007;
char s[110];
LL dp[10][1000][10];
LL sum,ans;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++)s[i]-=48;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<s[0];i++)dp[0][0][i]=1;
        int tmp=s[0];
        sum=0;
        char is=0;
        for(int i=1;i<len;i++){
            sum=sum*10%mod;
            for(int j=0;j<10;j++){
                for(int k=0;k<j;k++){
                    dp[1][i][j]+=dp[1][i-1][k];
                    dp[1][i][j]+=dp[0][i-1][k];
                }
                dp[1][i][j]+=dp[1][i-1][j];
            }
            for(int j=0;j<10;j++){
                for(int k=9;k>j;k--){
                    dp[0][i][j]+=dp[0][i-1][k];
                    sum+=dp[1][i-1][k];
                }
                dp[0][i][j]+=dp[0][i-1][j];
            }
            for(int j=9;j>0;j--)dp[0][i][j]++;
            if(is==0){
                if(s[i]<=tmp){
                    tmp=s[i];
                    for(int j=tmp-1;j>=0;j--)dp[0][i][j]++;
                }else{
                    is=1;
                    for(int j=tmp;j>=0;j--)dp[0][i][j]++;
                    for(int j=tmp+1;j<s[i];j++)dp[1][i][j]++;
                    tmp=s[i];
                }
            }else if(is==1){
                if(s[i]<tmp){
                    is=2;
                    sum+=s[i];
                }else{
                    sum+=tmp;
                    for(int j=s[i]-1;j>=tmp;j--)dp[1][i][j]++;
                    tmp=s[i];
                }
            }else{
                sum+=s[i];
            }
            sum%=mod;
            for(int j=9;j>=0;j--){
                dp[0][i][j]%=mod;
                dp[1][i][j]%=mod;
            }
        }
        if(is==2)sum++;
        ans=0;
        for(int i=0;i<len;i++){
            ans=(ans*10+s[i])%mod;
        }
        ans=(ans-sum+mod)%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}

