
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int z[55][55][55];
int vis[55][55][55];
int color[55][55][55];
struct node{
    int x,y,z,step;
};
int a,b,c,n;
int tx[9]={1,-1,0,0,0,0};
int ty[9]={0,0,1,-1,0,0};
int tz[9]={0,0,0,0,1,-1};
int dfs(){
    vis[1][1][1]=0;
    vis[a][b][c]=1;
    color[1][1][1]=1;
    color[a][b][c]=2;
    queue<node> qs,qe;
    qs.push((node){1,1,1,0});
    qe.push((node){a,b,c,1});
    while((!qs.empty()) || (!qe.empty())){
        if(!qs.empty()){
            node u=qs.front();
            qs.pop();
            for(int i=0;i<6;i++){
                node v=u;
                v.x+=tx[i];v.y+=ty[i];v.z+=tz[i];
                if(z[v.x][v.y][v.z])continue;
                if(color[v.x][v.y][v.z]==0){
                    v.step++;
                    color[v.x][v.y][v.z]=1;
                    vis[v.x][v.y][v.z]=v.step;
                    qs.push(v);
                }else if(color[v.x][v.y][v.z]==2){
                    return u.step+vis[v.x][v.y][v.z];
                }
            }
        }
        if(!qe.empty()){
            node u=qe.front();
            qe.pop();
            for(int i=0;i<6;i++){
                node v=u;
                v.x+=tx[i];v.y+=ty[i];v.z+=tz[i];
                if(z[v.x][v.y][v.z])continue;
                if(color[v.x][v.y][v.z]==0){
                    v.step++;
                    color[v.x][v.y][v.z]=2;
                    vis[v.x][v.y][v.z]=v.step;
                    qe.push(v);
                }else if(color[v.x][v.y][v.z]==1){
                    return u.step+vis[v.x][v.y][v.z];
                }
            }
        }
    }
    return -1;
}
int main(){
   // freopen("in.txt","r",stdin);
   // freopen("out1.txt","w+",stdout);
   // system("chcp 936");
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&a,&b,&c,&n);
        memset(z,-1,sizeof(z));memset(vis,0,sizeof(vis));memset(color,0,sizeof(color));
        for(int i=1;i<=a;i++)for(int j=1;j<=b;j++)for(int k=1;k<=c;k++)scanf("%d",&z[i][j][k]);
        if(z[a][b][c]){
            printf("-1\n");
            continue;
        }
        int ans=dfs();
        printf("%d\n",ans>n?-1:ans);
    }
    return 0;
}

