
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int x[1010],y[1010];
int mp[4010],mc;
int z[4010][4010],zz[4010][4010];
bool vis[4010][4010];
int xx[4]={1,-1,0,0};
int yy[4]={0,0,1,-1};
struct node{
    int x,y;
};
int main(){
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;++cas){
        int n,k;
        scanf("%d%d",&n,&k);
        mc=0;
        for(int i=0;i<k;i++){
            scanf("%d%d",&x[i],&y[i]);
            y[i]=n-y[i]-1;
            mp[mc++]=x[i];
            mp[mc++]=x[i]+1;
            mp[mc++]=y[i];
            mp[mc++]=y[i]+1;
        }
        mp[mc++]=0;
        mp[mc++]=n;
        sort(mp,mp+mc);
//        printf("mc=%d\n",mc);
        mc=unique(mp,mp+mc)-mp-1;
//        printf("mc=%d\n",mc);
//        for(int i=0;i<=mc;++i){
//            printf("%d ",mp[i]);
//        }
//        printf("\n");
        for(int i=0;i<mc;++i)for(int j=0;j<mc;++j)z[i][j]=0,vis[i][j]=false;
        for(int i=0;i<k;++i){
            int px=lower_bound(mp,mp+mc,x[i])-mp;
            int py=lower_bound(mp,mp+mc,y[i])-mp;
            z[px][py]=-1;
        }
//        printf("add hl\n");
        node ss=(node){0,0};
        vis[0][0]=true;
        queue<node> qu;
        qu.push(ss);
        while(!qu.empty()){
            node now=qu.front();
//            printf("now:%d %d\n",now.x,now.y);
            qu.pop();
            for(int i=0;i<4;++i){
                int tx=now.x+xx[i],ty=now.y+yy[i];
                if(tx<0 || ty<0 || tx>=mc || ty>=mc || z[tx][ty]==-1 || vis[tx][ty])continue;
                vis[tx][ty]=true;
                qu.push((node){tx,ty});
            }
        }
//        printf("bfs\n");
        int fm=0,fz=0;
        for(int i=0;i<mc;++i){
            for(int j=0;j<mc;++j){
                if(vis[i][j]){
//                    printf("add:i=%d j=%d\n",i,j);
                    int lx=mp[i+1]-mp[i],ly=mp[j+1]-mp[j];
                    z[i][j]=lx*ly*5-((i==0 || (i>0 && !vis[i-1][j]))?ly:0)-((j==0 || (j>0 && !vis[i][j-1]))?lx:0)
                            -((i==mc-1 || (i<mc-1 && !vis[i+1][j]))?ly:0)-((j==mc-1 || (j<mc-1 && !vis[i][j+1]))?lx:0);
//                    printf("%d %d %d %d\n",((i==0 || (i>0 && !vis[i-1][j]))?ly:0),((j==0 || (j>0 && !vis[i][j-1]))?lx:0)
//                            ,((i==mc-1 || (j<mc-1 && !vis[i+1][j]))?ly:0),((j==mc-1 || (j<mc-1 && !vis[i][j+1]))?lx:0));
                    fm+=z[i][j];
//                    printf("%d ",z[i][j]);
//                    printf("ans=%d\n",z[i][j]);
                    if(i>j){
                        fz+=z[i][j];
                    }else if(i==j){
//                        printf("fz=%d\n",fz);
                        fz+=lx*(1+lx)/2*5-((i==0 || (i>0 && !vis[i-1][j]))?1:0)-((j==0 || (j>0 && !vis[i][j-1]))?1:0)
                            -((i==mc-1 || (i<mc-1 && !vis[i+1][j]))?lx:0)-((j==mc-1 || (j<mc-1 && !vis[i][j+1]))?lx:0);
//                        printf("i=%d j=%d fz=%d\n",i,j,fz);
                    }
                }
            }
//            printf("\n");
        }
//        printf("fz=%d fm=%d\n",fz,fm);
        int gcd=__gcd(fz,fm);
        fz/=gcd;fm/=gcd;
        printf("Case #%d: %d/%d\n",cas,fz,fm);
    }
    return 0;
}

