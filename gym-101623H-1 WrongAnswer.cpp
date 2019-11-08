
#include <bits/stdc++.h>;
using namespace std;
typedef long long ll;
ll calc(ll a,ll b,ll c)
{
    return a*a+b*b+c*c+7*min(a,min(b,c));
}
int main()
{
    int ca;
    cin>>ca;
    while(ca--)
    {
        ll a,b,c,d;
        ll ans=0;
        cin>>a>>b>>c>>d;
        ans=max(ans,calc(a+d,b,c));
        ans=max(ans,calc(a,b+d,c));
        ans=max(ans,calc(a,b,c+d));
        cout<<ans<<endl;
    }
    return 0;
}



