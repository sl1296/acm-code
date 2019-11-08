
#include<cstdio>
#include<queue>
using namespace std;
int mp[1010][1010];
bool vis[1010][1010];
struct node{
    int x,y;
};
int xx[8]={-1,-1,-1,0,0,1,1,1};
int yy[8]={-1,0,1,-1,1,-1,0,1};
int main(){
    int n,ax,ay,bx,by,cx,cy;
    scanf("%d%d%d%d%d%d%d",&n,&ax,&ay,&bx,&by,&cx,&cy);
    for(int i=1;i<=n;++i)mp[ax][i]=mp[i][ay]=1;
    int tx=ax,ty=ay;
    while(tx>0 && ty>0){
        mp[tx][ty]=1;
        --tx;
        --ty;
    }
    tx=ax,ty=ay;
    while(tx<=n && ty<=n){
        mp[tx][ty]=1;
        ++tx;
        ++ty;
    }
    tx=ax,ty=ay;
    while(tx<=n && ty>0){
        mp[tx][ty]=1;
        ++tx;
        --ty;
    }
    tx=ax,ty=ay;
    while(tx>0 && ty<=n){
        mp[tx][ty]=1;
        --tx;
        ++ty;
    }
//    for(int i=1;i<=8;++i){
//        for(int j=1;j<=n;j++){
//            printf("%d ",mp[i][j]);
//        }
//        printf("\n");
//    }
    queue<node> q;
    q.push((node){bx,by});
    vis[bx][by]=true;
    bool ans=false;
    while(!q.empty()){
        node now=q.front();
        q.pop();
        for(int i=0;i<8;++i){
            node add=(node){now.x+xx[i],now.y+yy[i]};
            if(add.x>0 && add.y>0 && add.x<=n && add.y<=n && !vis[add.x][add.y] && mp[add.x][add.y]==0){
                if(add.x==cx && add.y==cy){
                    ans=true;
                    goto en;
                }
                q.push(add);
                vis[add.x][add.y]=true;
            }
        }
    }
    en:
    if(ans)printf("YES\n");
    else printf("NO\n");
    return 0;
}

