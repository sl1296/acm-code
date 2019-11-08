
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[2][300000];
const int z=150000;
int a[110],b[110];
int main(){
    int n;
    while(~scanf("%d",&n)){
        int c1=z,c2=z;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            if(a[i]>0)c1+=a[i];else c2+=a[i];
        }
     //  printf("%d %d\n",c1,c2);
        for(int i=c2;i<=c1;i++)dp[1][i]=-999999999;
        dp[1][z]=0;
        for(int i=0;i<n;i++){
            int nn=i%2,pp=(i+1)%2;
            for(int j=c2;j<=c1;j++)dp[nn][j]=dp[pp][j];
            for(int j=c2;j<=c1;j++){
                int pre=j-a[i];
                if(pre<c2||pre>c1)continue;
                dp[nn][j]=max(dp[nn][j],dp[pp][pre]+b[i]);
            }
          //  for(int j=c2;j<=c1;j++)printf("%d(%d) ",dp[nn][j],j-z);
          //  printf("\n\n");
        }
        int ans=0;
        int np=(n-1)%2;
        for(int i=z;i<=c1;i++){
          //  printf("%d(%d) ",dp[np][i],i-z);
            if(dp[np][i]>=0)ans=max(ans,i-z+dp[np][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

