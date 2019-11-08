
#include <bits/stdc++.h>
using namespace std;
#define N 510
typedef long long ll;
int r[N][N],c[N][N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            scanf("%d%d",&r[i][j],&c[i][j]);
    }
    bool flag=true;
    for(int i=0;i<n;++i)
    {
        ll sum=0;
        for(int j=0;j<m;++j)
            sum+=c[i][j];
        if(sum) flag=false;
    }
    for(int j=0;j<m;++j)
    {
        ll sum=0;
        for(int i=0;i<n;++i)
            sum+=r[i][j];
        if(sum) flag=false;
    }
    if(flag) puts("Yes");
    else puts("No");
    return 0;
}

