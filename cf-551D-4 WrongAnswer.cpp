
#include <stdio.h>
#define ll unsigned __int64
ll n,k,mod,l;
struct jz{
    ll x[2][2];
};
jz one,f;
jz mul(jz a,jz b){
    int i,j,k;
    jz c;
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            c.x[i][j]=0;
            for(k=0;k<2;k++){
                c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j])%mod;
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
    //    printf("%I64d ",x);
    }
    return o;
}
ll qpo(ll a,ll x){
    ll r=1;
    while(x){
        if(x&1)r=(r*a)%mod;
        x>>=1;
        a=(a*a)%mod;
    }
    return r;
}
int main(){
    jz r;
    ll s,t1,t2,ans=0;
    int i;
    one.x[0][0]=one.x[1][1]=1;
    f.x[0][0]=f.x[0][1]=f.x[1][0]=1;
    scanf("%I64u%I64u%I64u%I64u",&n,&k,&l,&mod);
    if(l==64 || (1uLL<<l)>k){
        ans++;
        r=qpow(f,one,n+1);
        t1=r.x[0][0];
        t2=(qpo(2,n)+mod-t1)%mod;
   // printf("%I64d %I64d\n",t1,t2);
        for(i=0;i<l;i++){
            if(k&(1uLL<<i))ans=(ans*t2)%mod;
            else ans=(ans*t1)%mod;
    //        printf("%d :%I64d\n",i,ans);
        }
    }
    printf("%I64u\n",ans);
}

