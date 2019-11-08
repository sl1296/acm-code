
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char mp[1010][1010];
int jx,jy;
int time[1010][1010];
bool vis[1010][1010];
int tx[4]={1,-1,0,0};
int ty[4]={0,0,1,-1};
struct node{
    int x,y,step;
};
queue<node> qu,qq;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c;
        scanf("%d%d",&r,&c);
        for(int i=0;i<r+2;i++){
            for(int j=0;j<c+2;j++){
                vis[i][j]=false;
                mp[i][j]=0;
                time[i][j]=-1;
            }
        }
        while(!qu.empty())qu.pop();
        while(!qq.empty())qq.pop();
        for(int i=1;i<=r;i++){
            scanf("%s",&mp[i][1]);
            for(int j=1;j<=c;j++){
                if(mp[i][j]=='F'){
                    qq.push((node){i,j,0});
                    mp[i][j]='.';
                }else if(mp[i][j]=='J'){
                    jx=i;jy=j;
                    mp[i][j]='.';
                }
            }
        }
        while(!qq.empty()){
            node tmp=qq.front();
            qq.pop();
            time[tmp.x][tmp.y]=tmp.step;
            for(int i=0;i<4;i++){
                node add=(node){tmp.x+tx[i],tmp.y+ty[i],tmp.step+1};
                if(mp[add.x][add.y]=='.'&&time[add.x][add.y]==-1){
                    qq.push(add);
                }
            }
        }
        qu.push((node){jx,jy,0});
        vis[jx][jy]=true;
        int ans=-1;
        while(!qu.empty()){
            node tmp=qu.front();
            if(tmp.x==1||tmp.x==r||tmp.y==1||tmp.y==c){
                ans=tmp.step+1;
                break;
            }
            qu.pop();
            for(int i=0;i<4;i++){
                node add=(node){tmp.x+tx[i],tmp.y+ty[i],tmp.step+1};
                if(!vis[add.x][add.y]&&mp[add.x][add.y]=='.'&&add.step<time[add.x][add.y]){
                    vis[add.x][add.y]=true;
                    qu.push(add);
                }
            }
        }
        if(ans==-1){
            printf("IMPOSSIBLE\n");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}

