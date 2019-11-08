
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n;
int mp[55][55],dis[55][55];
long long dp[55][55];
bool vis[55][55];
struct node{
    int x,y,step;
    bool operator < (const node &p) const{
        return step>p.step;
    }
};
int tx[5]={0,0,1,-1};
int ty[5]={1,-1,0,0};
long long dfs(int x,int y){
    if(dp[x][y]>-1)return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<4;i++){
        int nx=x+tx[i];
        int ny=y+ty[i];
        if(nx<1||nx>n||ny<1||ny>n||dis[nx][ny]>=dis[x][y])continue;
        dp[x][y]+=dfs(nx,ny);
    }
    return dp[x][y];
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&mp[i][j]);
            }
        }
        memset(vis,false,sizeof(vis));
        priority_queue<node> qu;
        qu.push((node){n,n,mp[n][n]});
        vis[n][n]=true;
        while(!qu.empty()){
            node tmp=qu.top();
            qu.pop();
            dis[tmp.x][tmp.y]=tmp.step;
            for(int i=0;i<4;i++){
                int nx=tmp.x+tx[i];
                int ny=tmp.y+ty[i];
                if(nx<1||nx>n||ny<1||ny>n||vis[nx][ny])continue;
                vis[nx][ny]=true;
                qu.push((node){nx,ny,tmp.step+mp[nx][ny]});
            }
        }
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j]=-1;
        dp[n][n]=1;
        printf("%lld\n",dfs(1,1));
    }
    return 0;
}

