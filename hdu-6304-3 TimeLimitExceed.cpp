
#include<cstdio>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
//map<ll,ll> ma,xx;
inline ll cal(ll x){
//    ll tmp=ma[x];
//    if(tmp)return tmp;
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        r+=((ee-ss)/(i*2)+1)*t;
    }
//    ma[x]=r;
    return r;
}
inline ll cc(ll x){
    ll r=1;
    ll t=1;
    for(ll i=1;i<=x;i*=2,t++){
        ll ss=i,ee=x-x%(i*2)+i;
        if(ee>x)ee-=(i*2);
        ll sum1=ss+ee,sum2=(ee-ss)/(i*2)+1;
        if(sum1&1)sum2>>=1;else sum1>>=1;
        ll sum=(sum1%mod)*(sum2%mod)%mod*t%mod;
        r+=sum;
        if(r>=mod)r-=mod;
    }
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n;
        scanf("%lld",&n);
//        ll tmp=xx[n];
//        if(tmp){
//            printf("%lld\n",tmp);
//            continue;
//        }
        ll s=max(1LL,n/2-31),e=min(n,n/2+31);
        while(s<e){
            ll m=s+(e-s)/2;
            ll num=cal(m);
            if(num<n)s=m+1;else e=m;
        }
//        printf("s=%lld\n",s);
        ll ans=cc(s)-(cal(s)-n)*s%mod;
        if(ans<0)ans+=mod;
//        xx[n]=ans;
        printf("%lld\n",ans);
    }
    return 0;
}

