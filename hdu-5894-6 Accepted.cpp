
#include<cstdio>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
ll qmod(ll x,int n) {
    ll ans=1;
    for(; n; n>>=1) {
        if(n&1)ans=ans*x%mod;
        x=x*x%mod;
    }
    return ans;
}
ll C(int n,int m) {
    if(m>n)return 0;
    ll ans=1;
    for(int i=1; i<=m; i++) {
        ans=ans*((n+i-m)*qmod(i,mod-2)%mod)%mod;
    }
    return ans;
}
int main() {
    // freopen("f.txt","r",stdin);
    int T;
    scanf("%d",&T);
    ll n,m,k;
    while(T--) {
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==1)printf("%lld\n",n);
        else
            printf("%lld\n",(C(n-k*m-1,m-1)*n%mod)*qmod(m,mod-2)%mod);
    }
    return 0;
}

