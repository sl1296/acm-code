
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[110],b[110];
int dp[110][110];
struct node{
    int x,y,from,to;
    bool operator < (const node &p) const{
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
};
node pir[10010];
int pc;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        pc=0;
        scanf("%d%d",&x,&y);
        for(int i=1;i<=x;i++)scanf("%d",&a[i]);
        for(int i=1;i<=y;i++)scanf("%d",&b[i]);
        for(int i=1;i<=y;i++){
            for(int j=i+1;j<=y;j++){
                if(b[i]==b[j])continue;
                pir[pc++]=(node){b[i],b[j],i,j};
            }
        }
        sort(pir,pir+pc);
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=x;i++){
          //  printf("i=%d\n",i);
            for(int j=0;j<=y;j++){
                dp[i][j]=dp[i-1][j];
            //    printf("%d %d=%d\n",i,j,dp[i][j]);
            }
          //  printf("cal\n");
            for(int j=1;j<i;j++){
                if(a[i]==a[j])continue;
                int pos=lower_bound(pir,pir+pc,(node){a[i],a[j],0,0})-pir;
                while(pos<pc&&pir[pos].x==a[i]&&pir[pos].y==a[j]){
                  //  printf("pir:x=%d y=%d from=%d to=%d\n",pir[pos].x,pir[pos].y,pir[pos].from,pir[pos].to);
                    dp[i][pir[pos].to]=max(dp[i][pir[pos].to],dp[j-1][pir[pos].from-1]+2);
                  //  printf("%d %d=%d\n",i,pir[pos].to,dp[i][pir[pos].to]);
                    pos++;
                }
            }
         //   printf("re\n");
            for(int j=1;j<=y;j++){
                dp[i][j]=max(dp[i][j-1],dp[i][j]);
             //   printf("i=%d j=%d dp=%d\n",i,j,dp[i][j]);
            }
        }

        printf("%d\n",dp[x][y]);
    }
    return 0;
}

