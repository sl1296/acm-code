
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int n,d;
int a[N];
bool check()
{
    for(int i=2;i<=n;++i)
        if(abs(a[i]-a[i-1])>d) return false;
    return true;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&d);
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        bool flag=check();
        a[0]=a[1];a[n+1]=a[n];
        for(int i=1;i<=n;++i)
        {
            if(flag) break;
            int tmp=a[i];
            a[i]=(a[i-1]+a[i+1])/2;
            flag=check();
            a[i]=tmp;
        }
        if(flag) puts("Y");
        else puts("N");
    }
    return 0;
}


