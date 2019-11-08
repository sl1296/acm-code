
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll inv(ll a,ll n){
    if(a==1)return 1;
    return inv(n%a,n)*(n-n/a)%n;
}
int main(){
    int t;
    ll n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        if(m>=n){
            printf("%I64d\n",n);
        }else{
            ll ans=m*(n+1)%mod*inv(m+1,mod)%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}


