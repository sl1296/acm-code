
#include <bits/stdc++.h>
using namespace std;
#define N 100010
const int inf=0x3f3f3f3f;
bool vis[N];
vector<int> g[N];
int du[N],a[N],dp[N][2],sta[N];
int ca,n;
int main()
{
    int x,y;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
        {
            du[i]=0;g[i].clear();vis[i]=false;
            scanf("%d",&a[i]);
        }
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&x,&y);
            ++du[x];++du[y];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        for(int i=1;i<=n;++i)
        {
            dp[i][0]=dp[i][1]=0;
            if(a[i]==1) dp[i][0]=inf;
            if(a[i]==0) dp[i][1]=inf;
        }
        int top=0,x;
        for(int i=1;i<=n;++i)
            if(du[i]==1)
            {
                vis[i]=true;sta[++top]=i;
            }
        while(top)
        {
            x=sta[top--];
//            printf("%d %d %d ?\n",x,dp[x][0],dp[x][1]);
            for(int y:g[x])
            {
                dp[y][0]+=min(dp[x][0],dp[x][1]+1);
                dp[y][1]+=min(dp[x][0]+1,dp[x][1]);
                if(vis[y]) continue;
                --du[y];
                if(du[y]<2&&!vis[y])
                {
                    sta[++top]=y;vis[y]=true;
                }
            }
        }
        printf("%d\n",min(dp[x][0],dp[x][1]));
    }
    return 0;
}

