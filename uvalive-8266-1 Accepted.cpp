
#include <bits/stdc++.h>
using namespace std;
#define N 210
const int inf=0x3f3f3f3f;
int g[N][N],num[N];
int n,m;
int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        memset(g,0x3f,sizeof(g));
        for(int i=0;i<n;++i) g[i][i]=0;
        int x,y;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            g[x][y]=g[y][x]=1;
        }
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
//        for(int i=0;i<n;++i)
//        {
//            for(int j=0;j<n;++j)
//                printf("%d ",g[i][j]);
//            printf("\n");
//        }
        memset(num,0,sizeof(num));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                ++num[g[i][j]];
        for(int i=1;i<=n;++i)
            if(num[i]) printf("%d %d\n",i,num[i]);
    }
    return 0;
}


