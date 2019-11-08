
#include <cstdio>
#define ll __int64
#define mod 1000000007
ll jc[2000010],res[1000010];
void exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if (b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
ll c(ll n,ll k){
    ll i,r=1;
    for(i=1;i<=k;i++)r=r*(n-i+1)/i;
    return r;
}
int main(){
    int n,t,i,z;
    ll a,b,re;
    jc[0]=1;res[0]=1;
    for(i=1;i<2000005;i++)jc[i]=(jc[i-1]*i)%mod;
    for(i=1;i<1000005;i++){
        exgcd(jc[i],mod,a,b);
        res[i]=(a%mod+mod)%mod;
    }
    scanf("%d",&t);
    for(z=0;z<t;z++){
        scanf("%d",&n);
        re=0;
        for(i=0;i+i<=n;i++){
            a=jc[i+i]*res[i+1]%mod*res[i]%mod;
            a=a*jc[n]%mod*res[2*i]%mod*res[n-2*i]%mod;
            re=(re+a)%mod;
        }
        printf("%I64d\n",re);
    }
}

