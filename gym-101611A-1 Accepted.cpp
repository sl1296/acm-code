
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k;
int calc(ll n, int k1,int k2)
{
    int cnt=1;
    ll a=0,b=k1;
    while(true)
    {
        ++cnt;
        a=b+min(b,(n-b)/2);
        if(a+k2>=n) break;
        b=a;
    }
    return cnt;
}
int main()
{
    scanf("%I64d%d",&n,&k);
    if(k>=n)
    {
        puts("1");
        return 0;
    }
    int ans=1e9;
    for(int i=1;i<k;++i)
        ans=min(ans,calc(n,i,k-i));
    printf("%d\n",ans);
    return 0;
}


