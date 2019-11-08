
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define N 100010
int ca,n;
set<int> se;
int a[N],b[N];
int main()
{
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        se.clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            se.insert(a[i]);
        }
        int ans;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&b[i]);
            if(se.count(b[i]))
                ans=b[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

