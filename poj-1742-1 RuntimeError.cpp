
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool dp[100010];
int num[100010];
int a[110],c[110];
int main(){
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        for(int i=0;i<n;i++)scanf("%d",&c[i]);
        for(int i=1;i<=m;i++)dp[i]=false;
        dp[0]=true;
        for(int i=0;i<n;i++){
            memset(num,0,sizeof(num));
            for(int j=1;j<=m;j++){
                if(!dp[j]&&dp[j-a[i]]&&num[j-a[i]]<c[i]){
                    num[j]=num[j-a[i]]+1;
                    dp[j]=true;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)if(dp[i])ans++;
        printf("%d\n",ans);
    }
    return 0;
}

