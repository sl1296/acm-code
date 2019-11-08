
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w[1010],a[1010],b[1010];
int dp[2010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&w[i],&a[i],&b[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=m;j>=0;j--){
                for(int k=j-w[i],cc=1;k>=0;k-=w[i],cc++){
                    dp[j]=max(dp[j],dp[k]+a[i]*cc+b[i]);
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}

