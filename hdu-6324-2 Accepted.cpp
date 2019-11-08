
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int w[N],c[40];
int main()
{
    int ca,n;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&w[i]);
            for(int j=31;j>=0;--j)
                if((w[i]>>j)&1) ++c[j];
        }
        int x,y;
        for(int i=1;i<n;++i) scanf("%d%d",&x,&y);
        bool Q=false;
        for(int i=31;i>=0;--i)
            if(c[i]&1)
            {
                Q=true;break;
            }
        if(Q) puts("Q");
        else puts("D");
    }
    return 0;
}

