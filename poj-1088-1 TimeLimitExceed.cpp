
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int a[110][110];
int dp[110][110];
int xx[5]={0,0,1,-1};
int yy[5]={1,-1,0,0};
struct node{
    int x,y,step;
};
int dfs(int x,int y){
    int re=0;
    queue<node> qu;
    memset(dp,0,sizeof(dp));
    while(!qu.empty())qu.pop();
    qu.push((node){x,y,1});
    dp[x][y]=1;
    while(!qu.empty()){
        node tmp=qu.front();
        qu.pop();
        for(int i=0;i<4;i++){
            node ad=(node){tmp.x+xx[i],tmp.y+yy[i],tmp.step+1};
            if(a[ad.x][ad.y]>=a[tmp.x][tmp.y]||ad.step<=dp[ad.x][ad.y])continue;
            dp[ad.x][ad.y]=ad.step;
            re=max(re,ad.step);
            qu.push(ad);
        }
    }
    return re;
}
int main(){
    int r,c;
    while(~scanf("%d%d",&r,&c)){
        for(int i=1;i<=r;i++)for(int j=1;j<=c;j++)scanf("%d",&a[i][j]);
        for(int i=0;i<c+2;i++)a[0][i]=a[r+1][i]=9999999;
        for(int i=1;i<=r;i++)a[i][0]=a[i][c+1]=9999999;
        int ans=0;
        for(int i=1;i<=r;i++)for(int j=1;j<=c;j++){
            int cnt=0;
            for(int k=0;k<4;k++)if(a[i][j]>=a[i+xx[k]][j+yy[k]]||a[i+xx[k]][j+yy[k]]==9999999)cnt++;
            if(cnt==4)ans=max(ans,dfs(i,j));
        }
        printf("%d\n",ans);
    }
    return 0;
}


