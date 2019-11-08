
#include<cstdio>
#include<cstring>
#define N 4
#define ll long long
const ll mod=1e9+7;
struct jz{
    ll x[N][N];
};
jz one;
jz mul(jz a,jz b){
    jz c;
    memset(c.x,0,sizeof(c.x));
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
        if(a.x[i][k]==0)continue;
            for(int j=0;j<N;j++){
                if(b.x[k][j]==0)continue;
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
    }
    return o;
}
ll ve[4],re[4];
jz cal;
int main(){
    memset(one.x,0,sizeof(one.x));
    for(int i=0;i<N;i++)one.x[i][i]=1;
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,d,p,n,cx[4];
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&n);
        if(n<=100000){
            cx[1]=a;
            cx[2]=b;
            for(int i=3;i<=n;++i){
                cx[i&3]=cx[(i+2)&3]*c%mod+cx[(i+3)&3]*d%mod+p/i;
                while(cx[i&3]>=mod)cx[i&3]-=mod;
            }
            printf("%lld\n",cx[n&3]);
        }else{
            cx[1]=a;
            cx[2]=b;
            for(ll i=3;i<=100000;++i){
                cx[i&3]=cx[(i+2)&3]*c%mod+cx[(i+3)&3]*d%mod+p/i;
                while(cx[i&3]>=mod)cx[i&3]-=mod;
            }
            ll st=p/100001,pre=100000;
            memset(cal.x,0,sizeof(cal.x));
            cal.x[0][0]=d;
            cal.x[0][1]=c;
            cal.x[0][3]=1;
            cal.x[1][0]=1;
            cal.x[2][1]=1;
            cal.x[3][3]=1;
            ve[0]=cx[pre&3];
            ve[1]=cx[(pre+3)&3];
            ve[2]=cx[(pre+2)&3];
            for(ll i=st;i>=0;--i){
//                printf("i=%d pre=%lld\n",i,pre);
                ll ff=pre,tt=(i==0?n:(p/i));
                if(tt>n)tt=n;
                ll cnt=tt-ff;
                ve[3]=i;
//                printf("%lld %lld\n",tt,cnt);
                jz ret=qpow(cal,one,cnt);
                memset(re,0,sizeof(re));
                for(int ii=0;ii<4;++ii){
                    for(int jj=0;jj<4;++jj){
                        re[ii]+=ret.x[ii][jj]*ve[jj]%mod;
                        if(re[ii]>=mod)re[ii]-=mod;
                    }
                }
                for(int ii=0;ii<4;++ii)ve[ii]=re[ii];
                pre=tt;
            }
            printf("%lld\n",ve[0]);
        }
    }
    return 0;
}
/*
1561
123165 48 154 4548 1635456 1251554
5661531 154584 128 66 84635 1455145
64 5646834 654684 456 237 848615
935104347
227907853
665586510
*/

