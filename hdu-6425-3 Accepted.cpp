
#include<cstdio>
#define ll long long
const ll mod= 998244353;
ll qpow(ll m,ll n){
    ll b=1;
    while(n){
        if(n&1)b=(b*m)%mod;
        n>>=1;
        m=(m*m)%mod;
    }
    return b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ll now=0;
        if(b>1 && c>0){
            ll ka=qpow(2,b)-1-b;
            if(ka<0)ka+=mod;
            ll kb=qpow(2,c)-1;
            if(kb<0)kb+=mod;
            now=ka*kb%mod*qpow(2,a)%mod;
        }
        if(d>0 && d+b>1){
            ll ka=qpow(2,b+d)-1-b-d;
            if(ka<0)ka+=mod;
            ll kb=0;
            if(b>1){
                kb=qpow(2,b)-1-b;
                if(kb<0)kb+=mod;
            }
            ka-=kb;
            if(ka<0)ka+=mod;
            now+=ka*qpow(2,a+c)%mod;
            if(now>=mod)now-=mod;
        }
        now=qpow(2,a+b+c+d)-now;
        if(now<0)now+=mod;
        printf("%lld\n",now);
    }
    return 0;
}

