
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int w[N];
int main()
{
    int ca,n;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        int tot=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&w[i]);
            tot^=w[i];
        }
        int x,y;
        for(int i=1;i<n;++i)
            scanf("%d%d",&x,&y);
        bool Q=false,D=false;
        for(int i=1;i<=n;++i)
        {
            if(w[i]>tot^w[i])
                Q=true;
            else if(w[i]==tot^w[i])
                D=true;
        }
        if(Q) puts("Q");
        else if(D) puts("D");
        else puts("T");
    }
    return 0;
}



