
#include <cstdio>
#include <queue>
using namespace std;
int n,m,t;
int xx[5]={-1,0,1,0};
int yy[5]={0,1,0,-1};
char z[22][22];
struct po{
    int x,y,zt,step;
};
int ex,ey;
int exi;
int main(){
    queue<po> q;
    po l,r;
    int i,j;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF){
        exi=0;
        for(i=1;i<=n;i++){
            scanf("%s",&z[i][1]);
            for(j=1;j<=m;j++){
                if(z[i][j]=='@'){
                    l.x=i;l.y=j;l.zt=l.step=0;z[i][j]='.';
                }else if(z[i][j]=='^'){
                    ex=i;ey=j;
                }
            }
        }
        for(i=1;i<m+2;i++)z[n+1][i]=0;
        q.push(l);
        while(!q.empty()){
            l=q.front();
            q.pop();
            for(i=0;i<4;i++){
                r.x=l.x+xx[i];
                r.y=l.y+yy[i];
                r.step=l.step+1;
                if(r.step>t){
                    printf("-1\n");
                    exi=1;
                    break;
                }
                r.zt=l.zt;
                //printf("%d %d %d %d\n",r.x,r.y,r.step,r.zt);
                if(z[r.x][r.y]==0 || z[r.x][r.y]=='*')continue;
                //printf("1\n");
                //getchar();
                if(z[r.x][r.y]=='^'){
                    //printf("4\n");
                    printf("%d\n",r.step);
                    exi=1;
                    break;
                }else if(z[r.x][r.y]=='.'){
                    //printf("0\n");
                    q.push(r);
                }else if(z[r.x][r.y]>='a'){
                    r.zt=r.zt|(1<<(z[r.x][r.y]-'a'));
                    q.push(r);
                    //printf("2\n");
                }else{
                    if(r.zt&(1<<(z[r.x][r.y]-'A'))){
                        q.push(r);
                        //printf("3\n");
                    }
                }
            }
            if(exi)break;
        }
        if(!exi)printf("-1\n");
    }
}

