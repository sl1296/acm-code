
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
char z[1010][1010];
bool is[1010][1010];
int r,c,t,sx,sy,ex,ey;
int dx[10]={-1,-1,0,1,1,1,0,-1};
int dy[10]={0,1,1,1,0,-1,-1,-1};
typedef struct point{
    int x,y,step;
}point;
bool re;
int ans;
queue<point> s;
void dfs(point x){
    int d;
    point l;
    if(x.x==ex && x.y==ey){
        re=true;
        ans=x.step;
        return;
    }
    s.push(x);
    is[x.x][x.y]=true;
    d=z[x.x][x.y]-48;
    l.x=x.x+dx[d];
    l.y=x.y+dy[d];
    if(is[l.x][l.y])return;
    l.step=x.step;
    dfs(l);
}
int main(){
    point l,k;
    int i,j,d;
    while(scanf("%d%d",&r,&c)!=EOF){
    for(i=1;i<=r;i++)scanf("%s",&z[i][1]);
    for(i=0;i<r+2;i++)is[i][0]=is[i][c+1]=true;
    for(i=1;i<=c;i++)is[0][i]=is[r+1][i]=true;
    scanf("%d",&t);
    while(t--){
        re=false;
        for(i=1;i<=r;i++)for(j=1;j<=c;j++)is[i][j]=false;
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        if(sx==ex && sy==ey){
            printf("0\n");
            continue;
        }
        while(!s.empty())s.pop();
        l.x=sx;
        l.y=sy;
        l.step=0;
        s.push(l);
        dfs(l);
        if(re){
            printf("%d\n",ans);
            continue;
        }
        while(!s.empty()){
            l=s.front();
            s.pop();
            d=z[l.x][l.y]-48;
            for(i=0;i<8;i++){
                k.x=l.x+dx[i];
                k.y=l.y+dy[i];
                if(i!=d && !is[k.x][k.y]){
                    k.step=l.step+1;
                    dfs(k);
                    if(re){
                        printf("%d\n",ans);
                        break;
                    }
                }
            }
            if(re)break;
        }
    }
    }
    return 0;
}

