
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char in[11];
int z[110];
int stat[65],cnt[65],statc;
int dp[110][65][65];

int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%s",in);
            z[i]=0;
            for(int j=0;j<m;j++){
                if(in[j]=='H')z[i]|=(1<<j);
            }
        }
        memset(dp,0,sizeof(dp));
        statc=0;
        for(int i=0;i<(1<<m);i++){
            if(i&(i>>1)||i&(i>>2))continue;
            stat[statc]=i;
            cnt[statc]=0;
            int j=1;
            while(j<=i){
                if(j&i)cnt[statc]++;
                j<<=1;
            }
            statc++;
        }
        for(int i=0;i<statc;i++){
            if(stat[i]&z[0])continue;
            dp[0][i][0]=cnt[i];
        }
        for(int i=0;i<statc;i++){
            if(stat[i]&z[1])continue;
            for(int j=0;j<statc;j++){
                if((stat[j]&z[0])||(stat[i]&stat[j]))continue;
                dp[1][i][j]=dp[0][j][0]+cnt[i];
            }
        }
        for(int i=2;i<n;i++){
            for(int j=0;j<statc;j++){
                if(stat[j]&z[i])continue;
                for(int k=0;k<statc;k++){
                    if((stat[k]&z[i-1])||(stat[k]&stat[j]))continue;
                    for(int l=0;l<statc;l++){
                        if((stat[l]&z[i-2])||(stat[l]&stat[k])||(stat[l]&stat[j]))continue;
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][l]+cnt[j]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<statc;i++){
            for(int j=0;j<statc;j++){
                ans=max(ans,dp[n-1][i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

