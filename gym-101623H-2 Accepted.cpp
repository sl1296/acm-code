
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
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        if(b>c)swap(b,c);
        ll now=a;
        for(int i=0;i<20;++i,++now){
            ll add=max(now-a,0LL)+max(now-b,0LL)+max(now-c,0LL);
            if(add>d)break;
            a=max(a,now);
            b=max(b,now);
            c=max(c,now);
            d-=add;
            ans=max(ans,calc(a,b,c+d));
        }
//        ans=max(ans,calc(a+d,b,c));
//        ans=max(ans,calc(a,b+d,c));
//        ans=max(ans,calc(a,b,c+d));
        cout<<ans<<endl;
    }
    return 0;
}


