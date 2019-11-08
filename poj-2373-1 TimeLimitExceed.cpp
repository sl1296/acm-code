
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=2147480000,INE=2147483600;
int dp[1000010];
int main(){
    int n,l,a,b,s,e;
    while(~scanf("%d%d%d%d",&n,&l,&a,&b)){
        bool is=true;
        if(l&1)is=false;
        dp[0]=0;
        for(int i=1;i<=l;i++)dp[i]=INF;
        for(int i=0;i<n;i++){
            scanf("%d%d",&s,&e);
            if(e-s>b*2)is=false;
            if(is)for(int j=s+1;j<e;j++)dp[j]=INE;
        }
        if(!is){
            printf("-1\n");
            continue;
        }
        for(int i=2*a;i<=l;i++){
            if(dp[i]==INE)continue;
            int en=i-2*b;
            for(int j=i-2*a;j>=en;j-=2){
                if(j<0)break;
              //  printf("j=%d dpi=%d dpj=%d\n",j,dp[i],dp[j]);
                dp[i]=min(dp[i],dp[j]+1);
            }
         //   printf("i=%d dp=%d\n",i,dp[i]);
        }
        printf("%d\n",dp[l]);
    }
    return 0;
}

