
#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 20;
struct node{
    int x,y,step,num,f;
};
char mapp[maxn][maxn];
vector<int> mapp2[maxn][maxn];
int sz[maxn][maxn];
int data[maxn][4] ;
int addx[5] = {0,0,1,-1};
int addy[5] = {-1,1,0,0};
int n,m ;
bool vis[maxn][maxn][1<<16];
bool ret;
int re;
queue<node> qq;
void dfs(node top){
    for(int j=0;j<sz[top.x][top.y];j++){
        int k=mapp2[top.x][top.y][j];
        if(top.f&(1<<k))continue ;
        node newnode=(node){data[k][2],data[k][3],top.step,top.num+1,top.f|(1<<k)};
        if(vis[newnode.x][newnode.y][newnode.f])continue;
        if(newnode.num==m){
            ret=true;
            re=newnode.step;
            return;
        }
        vis[newnode.x][newnode.y][newnode.f]=true;
        qq.push(newnode);
        dfs(newnode);
        if(ret)return;
    }
}
int bfs(){
    while(!qq.empty())qq.pop();
    ret=false;
    for(int i=0;i<m;i++){
        node st=(node){data[i][2],data[i][3],0,1,1<<i};
        vis[st.x][st.y][st.f]=true;
        qq.push(st);
    }
    while(!qq.empty()){
        node top = qq.front() ;
        //printf("x = %d y = %d step=%d f=%d\n",top.x,top.y,top.step,top.f) ;
        qq.pop();
        dfs(top);
        if(ret)return re;
        for(int i=0;i<4;i++){
            node newnode=(node){top.x+addx[i],top.y+addy[i],top.step+1,top.num,top.f};
            if(mapp[newnode.x][newnode.y]!='.'||vis[newnode.x][newnode.y][newnode.f])continue;
            vis[newnode.x][newnode.y][newnode.f] = true ;
            qq.push(newnode) ;
        }
    }
    return -1 ;
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(mapp,0,sizeof(mapp));
        for(int i=1;i<=n;i++)scanf("%s",&mapp[i][1]);
        for(int i=0;i<18;i++)for(int j=0;j<18;j++)mapp2[i][j].clear();
        for(int i=0;i<m;i++){
            int x1,y1,x2,y2 ;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
            data[i][0] = x1 ;
            data[i][1] = y1 ;
            data[i][2] = x2 ;
            data[i][3] = y2 ;
            mapp2[x1][y1].push_back(i);
        }
        if(m<=1){
            printf("0\n");
            continue;
        }
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)sz[i][j]=mapp2[i][j].size();
        int ans=bfs();
        printf("%d\n",ans);
    }
    return 0;
}

