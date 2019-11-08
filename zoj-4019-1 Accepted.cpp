
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 2010
int s1[maxn],s2[maxn];
ll k1,k2,c;
ll dp[maxn][maxn];
int pre1[maxn],pre2[maxn];
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        scanf("%lld%lld%lld",&k1,&k2,&c);
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&s1[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&s2[i]);
        sort(s1+1,s1+1+n);
        sort(s2+1,s2+1+m);
        for(int i=1;i<=n;i++){
            pre1[i]=pre1[i-1]+s1[i];
            if(pre1[i]>c){
                n=i-1;break;
            }
        }
        for(int i=1;i<=m;i++){
            pre2[i]=pre2[i-1]+s2[i];
            if(pre2[i]>c){
                m=i-1;break;
            }
        }
        ll ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++)
                dp[i][j]=0;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(pre1[i]+pre2[j]>c) break;
                if(i) dp[i][j]=dp[i-1][j]+(c-pre1[i]-pre2[j])*k1;
                if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]+(c-pre1[i]-pre2[j])*k2);
                //dp[i][j]=max(dp[i][j-1]+(c-pre1[i]-pre2[j])*k2,dp[i-1][j]+(c-pre1[i]-pre2[j])*k1);
                ans=max(ans,dp[i][j]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

