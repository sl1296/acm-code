
#include<cstdio>
#define ll long long
const ll mod=1e9+7;
ll inv(ll a,ll n){
    if(a==1)return 1;
    return inv(n%a,n)*(n-n/a)%n;
}
ll c[1010][1010];
ll sum[1010][1010];
ll p2[1010];
int main(){
    for(int i=0;i<1005;++i)c[i][0]=1;
    for(int i=1;i<1005;++i)for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for(int i=0;i<1005;++i){
        for(int j=i;j>=0;--j){
            sum[i][j]=(c[i][j]+sum[i][j+1])%mod;
        }
    }
//    for(int i=0;i<10;++i){
//        for(int j=0;j<=i;++j){
//            printf("%lld ",sum[i][j]);
//        }
//        printf("\n");
//    }
    p2[0]=1;
    for(int i=1;i<1005;++i)p2[i]=p2[i-1]*2%mod;
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m;
        scanf("%I64d%I64d",&n,&m);
        if(n<m){
            printf("0\n");
        }else{
            ll ans=sum[n][m]*inv(p2[n],mod)%mod;
            printf("%I64d\n",ans);
        }
    }
    return 0;
}

