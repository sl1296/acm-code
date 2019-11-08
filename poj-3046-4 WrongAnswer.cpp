
#include <cstdio>
#include <cstring>

const int maxn = 1005;
const int mod = 1e6;
int a[maxn];
int s[maxn];
int dp[maxn][100005];

int main()
{
	int t, n, S, B;
	while (~scanf("%d %d %d %d", &t, &n, &S, &B))
	{
		memset(s, 0, sizeof(s));
		for (int i=1; i<=n; i++)
		{
			scanf("%d", &a[i]);
			s[a[i]]++;
		}
		int pre = 0;
		int last = 1;
		dp[1][1] = dp[1][0] = 1;
		for (int i=1; i<=t; i++)
		{
			dp[i][0] = 1;
			for (int j=1; j<=B; j++)
			{
				if (j-1-s[i-1]>=0)
				{
					dp[i][j] = (dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1-s[i-1]]+mod)%mod;
				}
				else
					dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
					
			}
		}
		int ans = 0;
		for (int i=S; i<=B; i++)
		{
			ans += dp[t][i];
			ans %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

