
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll c[2510][2510];
ll quickpow(ll m,ll n){
    ll b=1;
    while(n){
        if(n&1)b=b*m%mod;
        n>>=1;
        m=m*m%mod;
    }
    return b;
}
ll r[2510];
int main(){
    for(int i=0;i<2510;++i)c[i][0]=1;
    for(int i=1;i<2510;++i)for(int j=1;j<=i;++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1){
        if(k==1){
            printf("1\n");
        }else{
            printf("0\n");
        }
        return 0;
    }
    if(n<k){
        printf("0\n");
        return 0;
    }
    for(int i=2;i<=k;++i){
        r[i]=quickpow(i-1,n-1)*i%mod;
    }
    for(int i=3;i<=k;++i){
        for(int j=2;j<i;++j){
            r[i]=(r[i]+mod-r[j]*c[i][j]%mod)%mod;
        }
    }
    printf("%I64d\n",r[k]);
    return 0;
}

