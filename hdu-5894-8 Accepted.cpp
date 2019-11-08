
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll quickpow(ll m,ll n){
    ll b=1;
    while(n){
        if(n&1)b=(b*m)%mod;
        n>>=1;
        m=(m*m)%mod;
    }
    return b;
}
ll inv(ll a,ll n){
    return quickpow(a,n-2);
}
ll c(ll n,ll k){
    if(k>n)return 0;
    ll r=1;
    for(int i=1;i<=k;i++)r=r*(n+i-k)%mod*inv(i,mod)%mod;
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==1){
            printf("%lld\n",n%mod);
            continue;
        }
        ll ans=c(n-k*m-1,m-1)*n%mod*inv(m,mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

