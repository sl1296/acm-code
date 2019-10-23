
#include <bits/stdc++.h>
using namespace std;
#define N 310
int c[N][N];
int n;
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        int x,y,z;
        for(int i=1;i<=n*(n-1)/2;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            c[x][y]=c[y][x]=z;
        }
        int ans=0,mx=0;
        for(int i=1;i<=n;++i)
            for(int j=i+1;j<=n;++j)
                for(int k=j+1;k<=n;++k)
                    if(c[i][j]+c[j][k]+c[i][k]>mx)
                        mx=c[i][j]+c[j][k]+c[i][k];
        printf("%d\n",mx);
    }
    return 0;
}


