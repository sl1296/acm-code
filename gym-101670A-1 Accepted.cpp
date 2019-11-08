
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int a[N];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        if(n==1)
        {
            printf("%d\n",n);
            continue;
        }
        int j=n-2;
        for(;j>0;--j)
            if(a[j]-a[j+1]!=a[j+1]-a[j+2])
                break;
        printf("%d\n",j+1);
    }
    return 0;
}

