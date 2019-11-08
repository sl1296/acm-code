
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[210],c[210],len[210],cc;
int dp[210][210][210];
int dfs(int s,int e,int k){
    if(e<s)return 0;
    if(dp[s][e][k]!=-1)return dp[s][e][k];
    dp[s][e][k]=dfs(s,e-1,0)+(len[e]+k)*(len[e]+k);
    for(int i=s;i<e;i++){
        if(c[i]==c[e]){
            dp[s][e][k]=max(dp[s][e][k],dfs(s,i,k+len[e])+dfs(i+1,e-1,0));
        }
    }
    return dp[s][e][k];
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(dp,-1,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        cc=0;
        for(int i=0;i<n;i++){
            c[cc]=a[i];
            len[cc]=1;
            while(i+1<n&&a[i+1]==a[i]){
                i++;
                len[cc]++;
            }
            cc++;
        }
        printf("Case %d: %d\n",z,dfs(0,cc-1,0));
    }
    return 0;
}

