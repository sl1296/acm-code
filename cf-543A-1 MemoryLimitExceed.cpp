
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[510];
int dp[510][510][510];
int main(){
    int n,m,b,mod;
    while(~scanf("%d%d%d%d",&n,&m,&b,&mod)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)dp[i][0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=0;k<a[i];k++){
                    dp[i][j][k]=dp[i-1][j][k];
                }
                for(int k=a[i];k<=b;k++){
                   // printf("j=%d k=%d j-1=%d k-a[i]=%d\n",j,k,j-1,k-a[i]);
                    dp[i][j][k]=(dp[i-1][j][k]+dp[i][j-1][k-a[i]])%mod;
                }
            }
        /*    printf("i=%d\n",i);
            for(int j=0;j<=m;j++){
                for(int k=0;k<=b;k++){
                    printf("%d ",dp[i][j][k]);
                }
                printf("\n");
            }*/
        }
        int ans=0;
        for(int i=0;i<=b;i++){
            ans=(ans+dp[n][m][i])%mod;
        }
        printf("%d\n",ans);
    }
    return 0;
}

