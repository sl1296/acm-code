
#include<cstdio>
#include<cstring>
#define ull unsigned long long
struct node{
    ull s;
    int v;
};
node a[110];
ull dp[2][1010];
int dpnr[2][1010][110];
int dpsum[2][1010];
int main(){
    int t;
    scanf("%d",&t);
    for(int zz=1;zz<=t;zz++){
        int b,n;
        scanf("%d%d",&b,&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i].s,&a[i].v);
        }
        memset(dp,0,sizeof(dp));
        memset(dpsum,0,sizeof(dpsum));
        for(int i=0;i<2;i++)for(int j=0;j<1005;j++)dpnr[i][j][0]=0;
        for(int i=1;i<=n;i++){
            int pre=(i-1)%2;
            int now=i%2;
           // printf("i=%d pre=%d now=%d\na[i].s=%I64u a[i].v=%d\npre:",i,pre,now,a[i].s,a[i].v);
           // for(int yy=0;yy<=b;yy++)printf("%I64u ",dp[pre][yy]);printf("\n");
            for(int j=0;j<a[i].v;j++){
                dp[now][j]=dp[pre][j];
                dpsum[now][j]=dpsum[pre][j];
                for(int k=0;k<=dpnr[pre][j][0];k++)dpnr[now][j][k]=dpnr[pre][j][k];
            }
            for(int j=a[i].v;j<=b;j++){
                int from=j-a[i].v;
                ull ad=dp[pre][from]+a[i].s;
               // printf("  j=%d from=%d ad=%I64u dp[pre][j]=%I64u\n",j,from,ad,dp[pre][j]);
              //  printf("  dpsum[pre][from]+i=%d dpsum[pre][j]=%d\n",dpsum[pre][from]+i,dpsum[pre][j]);
                if(ad>dp[pre][j]||(ad==dp[pre][j]&&dpsum[pre][from]+i<dpsum[pre][j])){
                 //   printf("->add\n");
                    dp[now][j]=ad;
                    dpsum[now][j]=dpsum[pre][from]+i;
                    dpnr[now][j][0]=dpnr[pre][from][0]+1;
                    int k;
                    for(k=1;k<=dpnr[pre][from][0];k++)dpnr[now][j][k]=dpnr[pre][from][k];
                    dpnr[now][j][k]=i;
                   // printf("->state:ans=%I64u sum=%d ",dp[now][j],dpsum[now][j]);
                   // for(int jj=0;jj<dpnr[now][j][0];jj++)printf("%d ",dpnr[now][j][jj]);printf("\n");
                }else{
                  //  printf("->keep\n");
                    dp[now][j]=dp[pre][j];
                    dpsum[now][j]=dpsum[pre][j];
                    for(int k=0;k<=dpnr[pre][j][0];k++)dpnr[now][j][k]=dpnr[pre][j][k];
                  //  printf("->state:ans=%I64u sum=%d ",dp[now][j],dpsum[now][j]);
                  //  for(int jj=0;jj<dpnr[now][j][0];jj++)printf("%d ",dpnr[now][j][jj]);printf("\n");
                }
            }
        }
        int use=0;
        int nn=n%2;
        for(int i=1;i<=dpnr[nn][b][0];i++)use+=a[dpnr[nn][b][i]].v;
        printf("Case #%d:\n%I64u %d\n",zz,dp[n%2][b],use);
        for(int i=1;i<=dpnr[nn][b][0];i++){
            if(i>1)printf(" ");
            printf("%d",dpnr[nn][b][i]);
        }
        printf("\n");
    }
    return 0;
}

