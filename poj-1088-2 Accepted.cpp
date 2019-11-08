
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[110][110];
int dp[110][110];
int r,cc;
int dfs(int x,int y){
    if(dp[x][y])return dp[x][y];
    int e=0,b=0,c=0,d=0;
    if(x&&a[x-1][y]<a[x][y])e=dfs(x-1,y);
    if(x<r-1&&a[x+1][y]<a[x][y])b=dfs(x+1,y);
    if(y&&a[x][y-1]<a[x][y])c=dfs(x,y-1);
    if(y<cc-1&&a[x][y+1]<a[x][y])d=dfs(x,y+1);
    return dp[x][y]=max(max(e,b),max(c,d))+1;
}
int main(){
    while(~scanf("%d%d",&r,&cc)){
        for(int i=0;i<r;i++){
            for(int j=0;j<cc;j++){
                scanf("%d",&a[i][j]);
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<r;i++){
            for(int j=0;j<cc;j++){
                dfs(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<cc;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


