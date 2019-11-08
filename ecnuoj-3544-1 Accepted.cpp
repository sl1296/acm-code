
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,t;
    bool operator < (const node &p) const{
        return a/(double)t>p.a/(double)p.t;
    }
};
node x[100010];
int dp[310];
int main(){
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x[i].a,&x[i].t);
    }
    sort(x,x+n);
    for(int i=0;i<n;i++){
        for(int j=t;j>=x[i].t;j--){
            dp[j]=max(dp[j],dp[j-x[i].t]+x[i].a*(t-j));
        }
    }
    int ans=0;
    for(int i=0;i<=t;i++)ans=max(ans,dp[i]);
    printf("%d\n",ans);
    return 0;
}

