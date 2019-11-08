
#include<cstdio>
#include<cstring>
#define ull unsigned long long

ull dp[25][25][2];
bool is[25];
int ans[25],ansc;
int main(){
    dp[1][1][0]=dp[1][1][1]=1;
    for(int i=2;i<21;i++){
        for(int j=1;j<=i;j++){
            for(int k=1;k<j;k++)dp[i][j][0]+=dp[i-1][k][1];
            for(int k=j;k<=i;k++)dp[i][j][1]+=dp[i-1][k][0];
      //      printf("dp[%d][%d][0]=%llu dp[%d][%d][1]=%llu\n",i,j,dp[i][j][0],i,j,dp[i][j][1]);
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        ull c;
        ansc=0;
        scanf("%d%llu",&n,&c);
        memset(is,false,sizeof(is));
        int zt,s,e;
        for(int i=1;i<=n;i++){
            for(int j=0;j<2;j++){
                c-=dp[n][i][j];
                if(c<=0){
                    c+=dp[n][i][j];
                    zt=j;
                    is[i]=true;
                    ans[ansc++]=i;
                    if(j)s=i+1,e=n;else s=1,e=i-1;
                    goto enn;
                }
            }
        }
        enn:
        for(int i=n-1;i>0;i--){
          //  printf("i=%d\n",i);
            zt=!zt;
            int cnt=0;
            for(int j=1;j<s;j++)if(!is[j])cnt++;
         //   printf("s=%d e=%d\n",s,e);
            for(int j=s;j<=e;j++){
                if(is[j])continue;
              //  printf("  j=%d\n",j);
                cnt++;
             //   printf("  c=%llu i=%d cnt=%d zt=%d\n",c,i,cnt,zt);
                c-=dp[i][cnt][zt];
             //   printf("  c=%llu\n",c);
                if(c<=0){
                    c+=dp[i][cnt][zt];
                    is[j]=true;
                    ans[ansc++]=j;
                    if(zt)s=j+1,e=n;else s=1,e=j-1;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(i)printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}

