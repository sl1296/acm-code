
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int z[9][9];
bool vis[9][9][9][9];
int xx,xy,sx,sy,tx,ty;
struct node{
    int x,y,xx,xy,step;
    bool operator < (const node &p) const{
        return step>p.step;
    }
};
int addx[5]={0,0,1,-1};
int addy[5]={1,-1,0,0};
int main(){
  //  system("chcp 936");
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        memset(z,-1,sizeof(z));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&z[i][j]);
                if(z[i][j]==2){
                    z[i][j]=0;
                    xx=i;xy=j;
                }else if(z[i][j]==3){
                    z[i][j]=0;
                    tx=i,ty=j;
                }else if(z[i][j]==4){
                    z[i][j]=0;
                    sx=i,sy=j;
                }
            }
        }
        priority_queue<node> qu;
        vis[sx][sy][xx][xy]=true;
        qu.push((node){sx,sy,xx,xy,0});
        int ans=-1;
        while(!qu.empty()){
            node u=qu.top();
            qu.pop();
            for(int i=0;i<4;i++){
                node v=(node){u.x+addx[i],u.y+addy[i],u.xx,u.xy,u.step};
                if(z[v.x][v.y])continue;
                if(v.x==v.xx&&v.y==v.xy){
                    v.xx+=addx[i];
                    v.xy+=addy[i];
                    if(z[v.xx][v.xy])continue;
                    v.step++;
                }
                if(vis[v.x][v.y][v.xx][v.xy])continue;
             //  printf("%d,%d %d,%d %d\n",v.x,v.y,v.xx,v.xy,v.step);
                if(v.xx==tx&&v.xy==ty){
                    ans=v.step;
                    goto ed;
                }
                vis[v.x][v.y][v.xx][v.xy]=true;
                qu.push(v);
            }
        }
        ed:
        printf("%d\n",ans);
    }
    return 0;
}

