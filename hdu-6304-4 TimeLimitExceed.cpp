
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll cal(ll x){
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        r+=((ee-ss)/(i*2)+1)*t;
    }
    return r;
}
ll cc(ll x){
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        ll sum1=ss+ee,sum2=(ee-ss)/(i*2)+1;
        if(sum1&1)sum2>>=1;else sum1>>=1;
        ll sum=(sum1%mod)*(sum2%mod)%mod*t%mod;
        r=(r+sum)%mod;
    }
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
        ll s=n/2,e=n/2+50;
        while(s<e){
            ll m=s+(e-s)/2;
            ll num=cal(m);
            if(num<n)s=m+1;else e=m;
        }
        ll ans=cc(s),dec=cal(s)-n;
        ans-=dec*s%mod;
        ans=(ans%mod+mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

