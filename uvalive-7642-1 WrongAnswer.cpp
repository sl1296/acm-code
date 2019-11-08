
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int prime[100010],pc;
int main(){
    memset(prime,0,sizeof(prime));
    int pc=0;
    for(ll i=2;i<100010;i++){
        if(prime[i]==0){
            for(ll j=i*i;j<100010;j+=i){
                prime[j]=1;
            }
        }
    }
    for(int i=2;i<100010;i++){
        if(prime[i]==0){
            prime[pc++]=i;
        }
    }
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--){
        ll n,m;
        scanf("%lld%lld",&n,&m);
        ll ans=n;
        for(int i=0;i<pc;i++){
            if(prime[i]<n){
                ans+=(n-prime[i])*(m-1)%mod;
                if(ans>=mod)ans-=mod;
            }else{
                break;
            }
        }
        for(int i=1;i<pc;i++){
            if(prime[i]>=n)break;
            if(prime[i]-prime[i-1]==2){
                ans+=(m-1)*(m-2)%mod*(n-prime[i])%mod;
                if(ans>=mod)ans-=mod;
            }
        }
        printf("Case %d: %lld\n",cas++,ans%mod);
    }
    return 0;
}


