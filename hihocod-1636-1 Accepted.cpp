
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
#define inf 0x3f3f3f3f
int n,L,R;
int a[maxn],dp[maxn][maxn][maxn],pres[maxn];
int dfs(int l,int r,int k){
    if(r-l+1<k) return dp[l][r][k]=inf;
    if(dp[l][r][k]!=-1) return dp[l][r][k];
    if(k==1){
        if(l==r) dp[l][r][k]=0;
        else{
            int ans=inf;
            for(int i=L;i<=R;i++)
                ans=min(ans,dfs(l,r,i)+pres[r]-pres[l-1]);
            dp[l][r][k]=ans;
        }
    }else{
        int ans=inf;
        for(int i=l;i<r;i++)
            ans=min(ans,dfs(l,i,1)+dfs(i+1,r,k-1));
        dp[l][r][k]=ans;
    }
//    printf("%d %d %d : %d\n",l,r,k,dp[l][r][k]);
    return dp[l][r][k];
}
int main(){
    while(scanf("%d%d%d",&n,&L,&R)!=EOF){
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            pres[i]=pres[i-1]+a[i];
        }
        int ans=dfs(1,n,1);
        printf("%d\n",ans==inf?0:ans);
    }
    return 0;
}
/*
3 2 2
1 2 3
*/

