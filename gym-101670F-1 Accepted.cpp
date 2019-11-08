
#include <bits/stdc++.h>
using namespace std;
#define N 5010
int a[N];
int dp[N][N];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                dp[i][j]=0;
        for(int len=2;len<=n;++len)
        {
            for(int l=1;l+len-1<=n;++l)
            {
                int r=l+len-1;
                dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
                if(a[l]==a[r]) dp[l][r]=max(dp[l][r],dp[l+1][r-1]+1);
            }
        }
        printf("%d\n",dp[1][n]);
    }
    return 0;
}

