
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w[1010],a[1010],b[1010];
int dp[2010];
bool is[2010];
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
            memset(is,false,sizeof(is));
            for(int j=w[i];j<=m;j++){
                if(is[j-w[i]]){
                    int cmp=dp[j-w[i]]+a[i];
                    if(dp[j]<cmp){
                        dp[j]=cmp;
                        is[j]=true;
                    }
                }else{
                    int cmp=dp[j-w[i]]+a[i]+b[i];
                    if(dp[j]<cmp){
                        dp[j]=cmp;
                        is[j]=true;
                    }
                }
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}

