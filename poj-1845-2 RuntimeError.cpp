
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=9901;
ll zys[5000],zysp[5000];
int zysn;
ll qpow(ll a,ll b){
    ll r=1;
    while(b){
        if(b&1)r=r*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return r;
}
ll dbs(ll a,ll b){
    if(b==1)return a%mod;
    ll re=0;
    if(b&1)re=(re+qpow(a,b))%mod;
    re=(re+(1+qpow(a,b/2))*dbs(a,b/2)%mod)%mod;
    return re;
}
int main(){
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)){
        zysn=0;
        ll tmp=a;
        for(int i=2;i*i<=tmp;i++){
            if(tmp%i==0){
                zys[zysn]=i;
                zysp[zysn]=0;
                while(tmp%i==0){
                    tmp/=i;
                    zysp[zysn]++;
                }
                zysp[zysn++]*=b;
            }
        }
        if(tmp>1)zys[zysn]=tmp,zysp[zysn++]=b;
        ll ans=1;
        for(int i=0;i<zysn;i++){
            ans=ans*(dbs(zys[i],zysp[i])+1)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

