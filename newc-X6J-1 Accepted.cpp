
#include<cstdio>
#include<cstring>
#define N 3
#define ll long long
const ll mod=1e9+7;
struct jz{
    ll x[N][N];
};
jz one;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    memset(c.x,0,sizeof(c.x));
    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
        if(a.x[i][k]==0)continue;
            for(j=0;j<N;j++){
                if(b.x[k][j]==0)continue;
                c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j]%mod)%mod;
            }
        }
    }
    return c;
}
jz qpow(jz a,jz o,ll x){
    while(x){
        if(x&1)o=mul(o,a);
        x>>=1;
        a=mul(a,a);
    }
    return o;
}
int main(){
    ll n,k,p;
    scanf("%lld%lld%lld",&n,&k,&p);
    for(int i=0;i<N;i++)one.x[i][i]=1;
    jz c=(jz){{k,0,1,1,1,0,0,0,1}};
    c=qpow(c,one,n);
    ll ve[3]={1,0,p};
    ll ans=0;
    for(int i=0;i<3;++i){
        ans+=ve[i]*c.x[1][i]%mod;
        if(ans>=mod)ans-=mod;
    }
    printf("%lld\n",ans);
}

