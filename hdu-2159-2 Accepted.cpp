
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF=2147483600;
int a[110],b[110];
int dp[110][110];
int main(){
    int n,m,k,s;
    while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
        for(int i=0;i<k;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                dp[i][j]=-INF;
            }
        }
        dp[0][0]=0;
        for(int i=0;i<k;i++){
            for(int j=m;j>=0;j--){
                for(int k=j-b[i],cc=1;k>=0;k-=b[i],cc++){
                    for(int l=0;l<=s-cc;l++){
                        dp[j][l+cc]=max(dp[j][l+cc],dp[k][l]+a[i]*cc);
                    }
                }
            }
        }
        int ans=-1;
        for(int i=0;i<=m;i++){
            dp[i][s+1]=0;
            for(int j=0;j<=s;j++){
                dp[i][s+1]=max(dp[i][s+1],dp[i][j]);
            }
            if(dp[i][s+1]>=n){
                ans=m-i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

