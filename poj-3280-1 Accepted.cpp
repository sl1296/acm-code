
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
char s[2010];
int cost[30];
int dp[2010][2010];
int main(){
    int n,m,i,j,x,y;
    char in[3];
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(dp,0,sizeof(dp));
        scanf("%s",s);
        for(i=0;i<n;i++){
            scanf("%s%d%d",in,&x,&y);
            cost[in[0]-'a']=min(x,y);
        }
        for(i=1;i<m;i++){
            for(j=i-1;j>-1;j--){
                dp[j][i]=min(dp[j+1][i]+cost[s[j]-'a'],dp[j][i-1]+cost[s[i]-'a']);
                if(s[i]==s[j])dp[j][i]=min(dp[j][i],dp[j+1][i-1]);
            }
        }
        printf("%d\n",dp[0][m-1]);
    }
    return 0;
}

