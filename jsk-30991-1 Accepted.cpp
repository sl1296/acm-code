
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 110
typedef long long ll;
int h[N][M];
int q1[M],q2[M];
int n,m,z;
int main()
{
    int ca;
    scanf("%d",&ca);
    for(int cas=1;cas<=ca;++cas)
    {
        scanf("%d%d%d",&n,&m,&z);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                h[i][j]=0;
        int x,y;
        for(int i=1;i<=z;++i)
        {
            scanf("%d%d",&x,&y);
            h[x][y]=x;
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(h[i][j]==0) h[i][j]=h[i-1][j];
        ll ans=0;
        for(int i=1;i<=n;++i)
        {
            int s=0,t=0,H;
            q1[0]=q2[0]=0;
            ll tmp=0;
            for(int j=1;j<=m;++j)
            {
                H=i-h[i][j];
                while(q2[t]>H)
                {
                    tmp-=(ll)q2[t]*(q1[t]-q1[t-1]);
                    --t;
                }
                tmp+=(ll)H*(j-q1[t]);
                ++t;
                q1[t]=j;q2[t]=H;
                ans+=tmp;
            }
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}

