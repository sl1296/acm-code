
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int z[55][55][55];
bool vis[55][55][55];
struct node{
    int x,y,z,step;
};
int tx[9]={0,0,0,0,1,-1};
int ty[9]={0,0,1,-1,0,0};
int tz[9]={1,-1,0,0,0,0};
int main(){
    //ystem("chcp 936");
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,n;
        scanf("%d%d%d%d",&a,&b,&c,&n);
        memset(z,-1,sizeof(z));
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    scanf("%d",&z[i][j][k]);
                }
            }
        }
        queue<node> qu;
        while(!qu.empty())qu.pop();
        vis[1][1][1]=true;
        qu.push((node){1,1,1,0});
        int ans=-1;
        while(!qu.empty()){
            node tmp=qu.front();
            qu.pop();
            if(tmp.step>n)break;
            for(int i=0;i<6;i++){
                node add=(node){tmp.x+tx[i],tmp.y+ty[i],tmp.z+tz[i],tmp.step+1};
                if(vis[add.x][add.y][add.z]==false&&z[add.x][add.y][add.z]==0){
                    if(add.x==a&&add.y==b&&add.z==c&&add.step<=n){
                        ans=add.step;
                        goto ed;
                    }
                    vis[add.x][add.y][add.z]=true;
                    qu.push(add);
                }
            }
        }
        ed:
        printf("%d\n",ans);
    }
    return 0;
}

