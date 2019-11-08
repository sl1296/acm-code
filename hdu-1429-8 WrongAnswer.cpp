
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
int n,m,t;
int xx[5]={-1,0,1,0};
int yy[5]={0,1,0,-1};
char z[25][25];
int mar[25][25][515];
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
        while(!q.empty())q.pop();
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
   /*     for(i=0;i<n+2;i++){
            for(j=0;j<m+2;j++){
                printf("%d ",z[i][j]);
            }
            printf("\n");
        }*/
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
                if(z[r.x][r.y]=='.' || z[r.x][r.y]=='@'){
                    r.zt=l.zt;
                    if(!mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }else if(z[r.x][r.y]>='A' && z[r.x][r.y]<='Z'){
                    r.zt=l.zt;
                    if((r.zt>>(z[r.x][r.y]-'A'))&1 && !mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }else{
                    r.zt=1<<(z[r.x][r.y]-'a');
                    r.zt=r.zt|l.zt;
                    if(!mar[r.x][r.y][r.zt]){
                        mar[r.x][r.y][r.zt]=1;
                        q.push(r);
                    }
                }
            }
            if(exi)break;
        }
        if(!exi)printf("-1\n");
    }
    return 0;
}

