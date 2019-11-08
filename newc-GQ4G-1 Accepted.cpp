
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll a[300010],w[300010];
int main(){
    int n;
    scanf("%d",&n);
    ll sum=0,ans=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
        sum+=a[i];
        if(sum>=mod)sum-=mod;
    }
    ll now=sum;
    for(int i=1;i<=n;++i){
        scanf("%lld",&w[i]);
        ans+=w[i]*sum%mod;
        if(ans>=mod)ans-=mod;
        now-=a[i]+a[n-i+1];
        while(now<0)now+=mod;
        sum+=now;
        if(sum>=mod)sum-=mod;
    }
    printf("%lld\n",ans);
    return 0;
}

