

#include <bits/stdc++.h>
using namespace std;
#define N 10010
typedef unsigned long long ull;
int a[N];
int n;
void calc(ull tmp)
{
    if(tmp&1) cout<<'-'<<tmp/2+1<<endl;
    else cout<<tmp/2<<endl;
}
int main()
{
    scanf("%d",&n);
    ull k=1,tmp=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        if(a[i]<128)
        {
            tmp+=k*a[i];
            calc(tmp);
            tmp=0;k=1;
        }
        else
        {
            tmp+=k*(a[i]-128);k*=128;
        }
    }
    return 0;
}

