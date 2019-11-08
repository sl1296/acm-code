
#include<cstdio>
#include<algorithm>
using namespace std;
int v[300];
char s[2010];
int dp[2010][2010];
int main(){
    int n,m;
    while(~scanf("%d%d%s",&n,&m,s)){
        for(int i=0;i<n;i++){
            char tt[5];
            int a,b;
            scanf("%s%d%d",tt,&a,&b);
            v[tt[0]]=min(a,b);
        }
        for(int i=0;i<m;i++)dp[i][i]=0;
        for(int i=1;i<m;i++){
            for(int j=0,k=i;k<m;j++,k++){
                dp[j][k]=min(dp[j+1][k]+v[s[j]],dp[j][k-1]+v[s[k]]);
                if(s[j]==s[k])dp[j][k]=min(dp[j][k],dp[j+1][k-1]);
            }
        }
        printf("%d\n",dp[0][m-1]);
    }
    return 0;
}

