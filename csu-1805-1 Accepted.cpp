
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll p2[100010],jc[400010],invjc[400010];
ll inv(ll a,ll n){
    if(a==1)return 1;
    return inv(n%a,n)*(n-n/a)%n;
}
inline ll C(ll n,ll k){
    return jc[n]*invjc[k]%mod*invjc[n-k]%mod;
}
int main(){
    p2[0]=1;
    for(int i=1;i<100005;++i)p2[i]=p2[i-1]*2%mod;
    jc[0]=1;
    invjc[0]=1;
    for(int i=1;i<400005;++i){
        jc[i]=jc[i-1]*i%mod;
        invjc[i]=inv(jc[i],mod);
    }
    ll a,b,c;
    while(~scanf("%lld%lld%lld",&a,&b,&c)){
        ll ans=0;
        ll mi=min(min(a,b),c);
        if(a&1 && b&1 && c&1){
            for(ll i=1;i<=mi;i+=2){
                ll tx=(a-i)/2;
                ll ty=(b-i)/2;
                ll tz=(c-i)/2;
                ans+=p2[i]*jc[tx+ty+i]%mod*invjc[tx]%mod*invjc[ty]%mod*invjc[i]%mod*C(tz+tx+ty+i-1,tx+ty+i-1)%mod*jc[a]%mod*jc[b]%mod*jc[c]%mod;
                if(ans>=mod)ans-=mod;
            }
            printf("%lld\n",ans);
        }else if(!(a&1) && !(b&1) && !(c&1)){
            for(ll i=0;i<=mi;i+=2){
                ll tx=(a-i)/2;
                ll ty=(b-i)/2;
                ll tz=(c-i)/2;
                ans+=p2[i]*jc[tx+ty+i]%mod*invjc[tx]%mod*invjc[ty]%mod*invjc[i]%mod*C(tz+tx+ty+i-1,tx+ty+i-1)%mod*jc[a]%mod*jc[b]%mod*jc[c]%mod;
                if(ans>=mod)ans-=mod;
            }
            printf("%lld\n",ans);
        }else{
            printf("0\n");
        }
    }
    return 0;
}


