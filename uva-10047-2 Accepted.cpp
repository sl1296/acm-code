
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool vis[30][30][5][4];
int tx[4]={1,-1,0,0};
int ty[4]={0,0,1,-1};
int ta[4]={2,3,1,0};
int tb[4]={3,2,0,1};
int sx,sy,ex,ey;
char mp[30][30];
struct node{
    int x,y,dir,st,step;
};
int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out1.txt","w+",stdout);
    int r,c,cas=1;
    while(1){
        scanf("%d%d",&r,&c);
        if(!r&&!c)break;
        memset(vis,false,sizeof(vis));
        memset(mp,0,sizeof(mp));
        for(int i=1;i<=r;i++){
            scanf("%s",&mp[i][1]);
            for(int j=1;j<=c;j++){
                if(mp[i][j]=='S'){
                    sx=i;sy=j;mp[i][j]='.';
                }else if(mp[i][j]=='T'){
                    ex=i;ey=j;mp[i][j]='.';
                }
            }
        }
        queue<node> qu;
        qu.push((node){sx,sy,1,0,0});
        vis[sx][sy][1][0]=true;
        int ans=-1;
        while(!qu.empty()){
            node tmp=qu.front();
//            printf("%d %d %d %d %d\n",tmp.x,tmp.y,tmp.st,tmp.dir,tmp.step);
            if(tmp.x==ex&&tmp.y==ey&&tmp.st==0){
                ans=tmp.step;
                break;
            }
            qu.pop();
            node add=tmp;
            add.step++;
            add.dir=ta[tmp.dir];
            if(!vis[add.x][add.y][add.st][add.dir]){
                vis[add.x][add.y][add.st][add.dir]=true;
                qu.push(add);
            }
            add.dir=tb[tmp.dir];
            if(!vis[add.x][add.y][add.st][add.dir]){
                vis[add.x][add.y][add.st][add.dir]=true;
                qu.push(add);
            }
            add.dir=tmp.dir;
            add.st=(add.st+1)%5;
            add.x+=tx[tmp.dir];
            add.y+=ty[tmp.dir];
            if(mp[add.x][add.y]=='.'&&!vis[add.x][add.y][add.st][add.dir]){
                vis[add.x][add.y][add.st][add.dir]=true;
                qu.push(add);
            }
        }
        if(cas>1)printf("\n");
        printf("Case #%d\n",cas++);
        if(ans==-1){
            printf("destination not reachable\n");
        }else{
            printf("minimum time = %d sec\n",ans);
        }
    }
    return 0;
}

