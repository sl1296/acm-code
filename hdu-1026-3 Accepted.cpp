
#include <cstdio>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
char z[110][110];
int dp[110][110],dr[110][110],rx[10010],ry[10010],rt[10010],rc;
int xx[5]={0,-1,0,1,0};
int yy[5]={0,0,1,0,-1};
struct po{
    int x,y,step,d;
};
int main(){
    int n,m,ll,i;
    po l,r;
    queue<po> q;
    while(scanf("%d%d",&m,&n)!=EOF){
        rc=0;
        memset(z,0,sizeof(z));
        memset(dp,0,sizeof(dp));
        memset(dr,0,sizeof(dr));
        for(i=1;i<=m;i++)scanf("%s",&z[i][1]);
        l.x=1;l.y=1;l.step=0;l.d=-1;q.push(l);dr[1][1]=-1;
        while(!q.empty()){
            l=q.front();
            q.pop();
            for(i=1;i<5;i++){
                r.x=l.x+xx[i];
                r.y=l.y+yy[i];
                if(z[r.x][r.y]=='X' || z[r.x][r.y]==0)continue;
                r.d=i;
                r.step=l.step+1;
                if(z[r.x][r.y]>48 && z[r.x][r.y]<58)r.step=r.step+z[r.x][r.y]-48;
                if(!dr[r.x][r.y] || (dr[r.x][r.y] && dp[r.x][r.y]>r.step)){
                    if(r.x!=m || r.y!=n)q.push(r);
                    dr[r.x][r.y]=i;
                    dp[r.x][r.y]=r.step;
                }
            }
        }
        if(!dr[m][n]){
            printf("God please help our poor hero.\nFINISH\n");
            continue;
        }
        while(1){
            rx[rc]=m-1;ry[rc]=n-1;rt[rc]=dp[m][n];rc++;
            if(dr[m][n]==-1)break;
            ll=dr[m][n];m-=xx[ll];n-=yy[ll];
        }
        printf("It takes %d seconds to reach the target position, let me show you the way.\n",rt[0]);
        i=0;
        for(rc-=2;rc>-1;rc--){
            i++;
            printf("%ds:(%d,%d)->(%d,%d)\n",i,rx[rc+1],ry[rc+1],rx[rc],ry[rc]);
            while(i<rt[rc]){
                i++;
                printf("%ds:FIGHT AT (%d,%d)\n",i,rx[rc],ry[rc]);
            }
        }
        printf("FINISH\n");
    }
    return 0;
}

