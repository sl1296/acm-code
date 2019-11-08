
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll prime[100010],pc;
ll oxx[100010];
ll oth[100010];
int main(){
    for(int i=1;i<100010;i++){
        oxx[i]=(oxx[i-1]+i)%mod;
    }
    for(int i=1;i<100010;i++){
        oth[i]=(oth[i-1]+oxx[i])%mod;
    }
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
        if(m>=2){
            for(int i=0;i<pc;i++){
                if(prime[i]<n){
                    ans+=(n-prime[i])*(m-1)%mod;
                    if(ans>=mod)ans-=mod;
                }else{
                    break;
                }
            }
        }
        if(m>=3){
            for(int i=1;i<pc;i++){
                if(prime[i]>=n)break;
                if(prime[i]-prime[i-1]==2){
                    ans+=(m-1)*(m-2)%mod*(n-prime[i])%mod;
                    if(ans>=mod)ans-=mod;
                }
            }
        }
        if(m>=4){
            for(int i=2;i<pc;i++){
                if(prime[i]>=n)break;
                if(prime[i]-prime[i-1]==2&&prime[i]-prime[i-2]==4){
                    ans+=oth[m-3]*(n-prime[i])%mod;
                    if(ans>=mod)ans-=mod;
                }
            }
        }
        printf("Case %d: %lld\n",cas++,ans%mod);
    }
    return 0;
}


