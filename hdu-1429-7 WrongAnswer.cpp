
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,m,t;
int xx[5]={-1,0,1,0};
int yy[5]={0,1,0,-1};
char z[22][22];
int mar[22][22][515];
struct po{
    int x,y,zt,step;
};
int exi;
int main(){
    queue<po> q;
    po l,r;
    int i,j;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        exi=0;
        memset(z,0,sizeof(z));
        memset(mar,0,sizeof(mar));
        for(i=1;i<=n;i++){
            scanf("%s",&z[i][1]);
            for(j=1;j<=m;j++){
                if(z[i][j]=='@'){
                    l.x=i;l.y=j;l.zt=l.step=0;mar[l.x][l.y][0]=1;
                }
            }
        }
        q.push(l);
        while(!q.empty()){
            l=q.front();
            q.pop();
            if(l.step>=t-1){
                printf("-1\n");
                exi=1;
                break;
            }
            r.step=l.step+1;
            for(i=0;i<4;i++){
                r.x=l.x+xx[i];
                r.y=l.y+yy[i];
                if(z[r.x][r.y]==0 || z[r.x][r.y]=='*')continue;
                if(z[r.x][r.y]=='^'){
                    printf("%d\n",r.step);
                    exi=1;
                    break;
                }
                r.zt=l.zt;
                if(z[r.x][r.y]=='.' || z[r.x][r.y]=='@'){
                    if(!mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }
                if(z[r.x][r.y]>='a' && z[r.x][r.y]<='z'){
                    r.zt=r.zt|(1<<(z[r.x][r.y]-'a'));
                    if(!mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }
                if(z[r.x][r.y]>='A' && z[r.x][r.y]<='Z'){
                    if(r.zt&(1<<(z[r.x][r.y]-'A')) && !mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }
            }
            if(exi)break;
        }
        if(!exi)printf("-1\n");
        while(!q.empty())q.pop();
    }
    return 0;
}

