
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int xb[100010][15];
int dp[100010][15];
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        memset(xb,0,sizeof(xb));
        memset(dp,0,sizeof(dp));
        int tt=0;
        for(int i=0;i<n;i++){
            int x,t;
            scanf("%d%d",&x,&t);
            if(t==1&&(x<4||x>6))continue;
            if(t==2&&(x<3||x>7))continue;
            if(t==3&&(x<2||x>8))continue;
            if(t==4&&(x<1||x>9))continue;
            xb[t][x+1]++;
            tt=max(tt,t);
        }
        dp[1][5]=xb[1][5];
        dp[1][6]=xb[1][6];
        dp[1][7]=xb[1][7];
        for(int i=2;i<=tt;i++){
            for(int j=1;j<=11;j++){
                dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+xb[i][j];
            }
        }
        int ans=0;
        for(int i=1;i<=11;i++){
            ans=max(ans,dp[tt][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}

