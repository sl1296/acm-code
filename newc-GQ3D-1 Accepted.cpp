
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int n,m;
int a[N],b[N];
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        int cnt=0;
        double sum=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&a[i],&b[i]);
            sum+=a[i];cnt+=b[i];
        }
        sort(a+1,a+n+1,greater<int>());
        cnt=min(cnt,m);
        for(int i=1;i<=cnt;++i)
            sum-=a[i]/2.0;
        printf("%.1f\n",sum);
    }
    return 0;
}

