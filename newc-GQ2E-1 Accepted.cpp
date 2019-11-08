
#include <bits/stdc++.h>
using namespace std;
#define N 15
int dp[1<<N],to[1<<N];
int g[N][N],b[1<<N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i) to[1<<i]=i;
    for(int i=1;i<=2*n*(n-1);++i)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        --x;--y;
        ++g[x][y];
    }
    for(int s=0;s<(1<<n);++s)
    {
        for(int i=0;i<n;++i)
            if((s>>i)&1)
                for(int j=i+1;j<n;++j)
                    if((s>>j)&1)
                        b[s]+=abs(g[i][j]-g[j][i]);
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int s=1;s<(1<<n);++s)
    {
        if(s&(s-1)==0) dp[s]=0;
        for(int ss=s;ss;ss=(ss-1)&s)
        {
            int res=s^ss;
            int z=0;
            for(int s1=res;s1;s1-=s1&-s1)
            {
                int p1=to[s1&-s1];
                for(int s2=ss;s2;s2-=s2&-s2)
                {
                    int p2=to[s2&-s2];
                    z+=g[p2][p1];
                }
            }
            // printf("%d %d %d ?\n",res,ss,z+b[ss]);
            dp[s]=min(dp[s],dp[res]+z+b[ss]);
        }
    }
    printf("%d\n",dp[(1<<n)-1]);
    return 0;
}

