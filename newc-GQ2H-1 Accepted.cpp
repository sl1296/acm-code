
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ca,n,m,k;
    scanf("%d",&ca);
    for(int cas=1;cas<=ca;++cas)
    {
        scanf("%d%d%d",&n,&m,&k);
        double ans=0;
        for(int i=0;i<k;++i)
            ans+=1.0*(n-i)/(m-i);
        printf("Case #%d: %.8f\n",cas,ans);
    }
    return 0;
}

