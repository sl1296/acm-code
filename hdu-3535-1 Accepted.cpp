
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int m[110],s[110];
int c[110][110],g[110][110];
int dp[110][110];
const int INF=2147483600;
int main(){
   // system("chcp 936");
	int n,t;
	while(~scanf("%d%d",&n,&t)){
		int re=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&m[i],&s[i]);
			int cc=INF;
			for(int j=0;j<m[i];j++){
				scanf("%d%d",&c[i][j],&g[i][j]);
				if(s[i]==0)cc=min(cc,c[i][j]);
			}
			if(s[i]==0)re+=cc;
		}
		if(re>t){
			printf("-1\n");
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=0;i<=n;i++){
			for(int j=0;j<=t;j++)dp[i][j]=(s[i]==0)?-INF:dp[i-1][j];
			dp[0][0]=0;
			for(int j=0;j<m[i];j++){
				for(int k=t;k>=c[i][j];k--){
					if(s[i]==0){
						dp[i][k]=max(dp[i][k],max(dp[i-1][k-c[i][j]]+g[i][j],dp[i][k-c[i][j]]+g[i][j]));
					}else if(s[i]==1){
						dp[i][k]=max(dp[i][k],dp[i-1][k-c[i][j]]+g[i][j]);
					}else{
						dp[i][k]=max(dp[i][k],dp[i][k-c[i][j]]+g[i][j]);
					}
				}
			}
		}
		/*for(int i=0;i<=n;i++){
            for(int j=0;j<=t;j++){
                printf("%d ",dp[i][j]);
            }
            printf("\n");
		}*/
		int ans=0;
		for(int i=0;i<=t;i++)ans=max(ans,dp[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}

