
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll tree[1000010];
int n;
inline int lowbit(int x){
    return x&-x;
}
inline void update(int x,ll v){
    for(int i=x;i<=n;i+=lowbit(i))tree[i]=tree[i]*v%mod;
}
inline ll query(int x){
    ll ret=1;
    for(int i=x;i>0;i-=lowbit(i))ret=ret*tree[i]%mod;
    return ret;
}
ll inv(ll a,ll n){
    if(a==1)return 1;
    return inv(n%a,n)*(n-n/a)%n;
}
int main(){
    int m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)tree[i]=1;
    while(m--){
        ll x,y,z;
        scanf("%lld%lld%lld",&x,&y,&z);
        if(x==1){
            update(y,z);
        }else if(x==2){
            update(y,inv(z,mod));
        }else{
            ll ans=query(z)*inv(query(y-1),mod)%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

