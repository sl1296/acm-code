
#include<cstdio>
#include<cstring>
char s[25][25];
bool vis[25][25];
int ans;
int tx[6]={0,0,1,-1};
int ty[6]={1,-1,0,0};
void dfs(int x,int y){
    ans++;
    vis[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+tx[i],ny=y+ty[i];
        if(vis[nx][ny]==false&&s[nx][ny]=='.')dfs(nx,ny);
    }
}
int main(){
    int x,y,sx,sy;
    while(1){
        memset(s,0,sizeof(s));
        memset(vis,false,sizeof(vis));
        scanf("%d%d",&y,&x);
        if(x==0&&y==0)break;
        for(int i=1;i<=x;i++){
            scanf("%s",&s[i][1]);
            for(int j=1;j<=y;j++){
                if(s[i][j]=='@')sx=i,sy=j;
            }
        }
        ans=0;
        dfs(sx,sy);
        printf("%d\n",ans);
    }
    return 0;
}

