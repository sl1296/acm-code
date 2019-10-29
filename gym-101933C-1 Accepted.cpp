
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int n;
bool f[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        f[x]=true;
    }
    int tot=0,t=0,cnt=0;
    for(int i=1;i<=365;++i)
    {
        t+=cnt;
        if(t>=20)
        {
            ++tot;t=cnt=0;
        }
        if(f[i]) ++cnt;
    }
    if(cnt) ++tot;
    printf("%d\n",tot);
    return 0;
}

