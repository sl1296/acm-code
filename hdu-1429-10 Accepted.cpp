
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char z[25][25];
bool vis[1050][25][25];
int sx,sy;
struct node{
    int x,y,stat,step;
};
int tx[5]={0,0,1,-1};
int ty[5]={1,-1,0,0};
int main(){
   // system("chcp 936");
    int n,m,t;
    while(~scanf("%d%d%d",&n,&m,&t)){
        memset(z,0,sizeof(z));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++){
            scanf("%s",&z[i][1]);
            for(int j=1;j<=m;j++){
                if(z[i][j]=='@'){
                    z[i][j]='.';
                    sx=i;sy=j;
                }
            }
        }
        queue<node> qu;
        vis[0][sx][sy]=true;
        qu.push((node){sx,sy,0,0});
        int ans=-1;
        while(!qu.empty()){
            node u=qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                node v=(node){u.x+tx[i],u.y+ty[i],u.stat,u.step+1};
                if(v.step>=t)continue;
             //   printf("1:%d %d %d %d\n",v.x,v.y,v.stat,v.step);
                if(z[v.x][v.y]=='*'||z[v.x][v.y]==0)continue;
                if(z[v.x][v.y]>='A'&&z[v.x][v.y]<='J'){
                   // printf("%d %d %d\n",1<<(z[v.x][v.y]-'A'),v.stat,(1<<(z[v.x][v.y]-'A'))&v.stat);
                    if(((1<<(z[v.x][v.y]-'A'))&v.stat)==0)continue;
                }
                if(z[v.x][v.y]=='^'&&v.step<t){
                    ans=v.step;
                    goto ed;
                }
                if(z[v.x][v.y]>='a'&&z[v.x][v.y]<='j'){
                    v.stat|=(1<<(z[v.x][v.y]-'a'));
                }
                if(vis[v.stat][v.x][v.y])continue;
              //  printf("%d %d %d %d\n",v.x,v.y,v.stat,v.step);
                vis[v.stat][v.x][v.y]=true;
                qu.push(v);
            }
        }
        ed:
        printf("%d\n",ans);
    }
    return 0;
}

