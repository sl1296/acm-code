
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll a[500010],b[500010],sum[500010];
int main(){
    int n,m,l,r;
    while(~scanf("%d%d%d%d",&n,&m,&l,&r)){
        for(int i=1;i<=n+1;++i){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=m+1;++i){
            scanf("%lld",&b[i]);
        }
        for(int i=1;i<=m+1;++i){
            sum[i]=sum[i-1]+b[i];
            if(sum[i]>=mod)sum[i]-=mod;
        }
        ll ans=0;
        for(int i=1;i<=r+1&&i<=n+1;++i){
            ans+=a[i]*((sum[max(0,min(m+1,r+2-i))]-sum[min(m+1,max(0,l+2-i-1))]+mod)%mod)%mod;
            if(ans>=mod)ans-=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

