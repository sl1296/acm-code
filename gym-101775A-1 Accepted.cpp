
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll inv[100010];
ll quickpow(ll m,ll n,ll mod){
    ll b=1;
    while(n){
        if(n&1)b=b*m%mod;
        n>>=1;
        m=m*m%mod;
    }
    return b;
}
int main(){
    inv[0]=inv[1]=1;
    for(int i=2;i<100005;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    int t,n,k;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        scanf("%d%d",&n,&k);
        ll ans=0,now=1;
        for(int i=0;i<k;++i){
            ans+=now;
            if(ans>=mod)ans-=mod;
            now=now*(n-i)%mod*inv[i+1]%mod;
        }
        ans=(quickpow(2,n,mod)-ans+mod)%mod;
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}

