
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(a==0&&b==0)return -1;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll inv(ll a,ll n){
    ll x,y;
    ll d=exgcd(a,n,x,y);
    if(d==1)return (x%n+n)%n;else return -1;
}
ll c(ll n,ll k){
    if(k>n)return 0;
    if(n-k<k)k=n-k;
    ll r=1;
    for(int i=1;i<=k;i++)r=r*(n-i+1)%mod*inv(i,mod)%mod;
    return r;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,k;
        scanf("%lld%lld%lld",&n,&m,&k);
        if(m==1){
            printf("%lld\n",n);
            continue;
        }
        ll ans=c(n-k*m-1,m-1)*n%mod*inv(m,mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

