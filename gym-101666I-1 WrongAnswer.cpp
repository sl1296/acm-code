
#include<cstdio>
#include<algorithm>
using namespace std;
int dp[110][110][2][2];
//zuo-xia hei-bai
int main(){
    dp[1][1][0][0]=dp[1][1][1][1]=1;
    dp[1][1][0][1]=dp[1][1][1][0]=-1;
    for(int i=3;i<201;++i){
        for(int j=max(1,i-100);j<=100&&i-j>=1;++j){
            int a=j,b=i-j;
//            if(a<=0||b<=0||a>100||b>100)printf("%d %d\n",a,b);
//            if(a<5&&b<5)printf("%d %d\n",a,b);
            dp[a][b][0][0]=0;
            dp[a][b][0][1]=0;
            for(int d=1;d<=b;++d){
                dp[a][b][0][0]=max(dp[a][b][0][0],((a&1)&&(d&1)?1:0)+dp[a][b-d][1][d&1]);
                dp[a][b][0][1]=max(dp[a][b][0][1],((a&1)&&(d&1)?-1:0)+dp[a][b-d][1][(d+1)&1]);
//                if(a<5&&b<5)printf("d=%d %d %d\n",d,dp[a][b][0][0],dp[a][b][0][1]);
            }
            dp[a][b][1][0]=9999999;
            dp[a][b][1][1]=9999999;
            for(int d=1;d<=a;++d){
                if(a&1){
                    dp[a][b][1][0]=min(dp[a][b][1][0],((b&1)&&(d&1)?-1:0)+dp[a-d][b][0][0]);
                    dp[a][b][1][1]=min(dp[a][b][1][1],((b&1)&&(d&1)?1:0)+dp[a-d][b][0][1]);
                }else{
                    dp[a][b][1][0]=min(dp[a][b][1][0],((b&1)&&(d&1)?1:0)+dp[a-d][b][0][0]);
                    dp[a][b][1][1]=min(dp[a][b][1][1],((b&1)&&(d&1)?-1:0)+dp[a-d][b][0][1]);
                }
            }
        }
    }
//    for(int i=0;i<5;++i){
//        for(int j=0;j<5;++j){
//            printf("(%d,%d,%d,%d) ",dp[i][j][0][0],dp[i][j][0][1],dp[i][j][1][0],dp[i][j][1][1]);
//        }
//        printf("\n");
//    }
    int x,y;
    while(~scanf("%d%d",&x,&y)){
        printf("%d\n",dp[x][y][0][0]);
    }
    return 0;
}

