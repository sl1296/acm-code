
#include<bits/stdc++.h>
using namespace std;
namespace IO {
    const int MX = 2e7; //1e7Õ¼ÓÃÄÚ´æ11000kb
    char buf[MX]; int c, sz;
    void begin() {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }
    inline bool read(int &t) {
        while(c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) c++;
        if(c >= sz) return false;
        bool flag = 0; if(buf[c] == '-') flag = 1, c++;
        for(t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++) t = t * 10 + buf[c] - '0';
        if(flag) t = -t;
        return true;
    }
}
typedef long long ll;
#define maxn 100010
#define mod 1000000007
#define mod2 1000000006
struct node{
    ll sum,mul,pow;
};
int a[maxn];
ll Pow(ll x,ll n){
    ll ans=1;
    while(n){
        if(n&1) ans=ans*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return ans;
}
struct SegTree{
    node v[maxn*4];
    void build(int o,int L,int R){
        if(L==R){
            v[o].sum=a[L];
            v[o].mul=v[o].pow=1;
        }else{
            int M=(L+R)/2;
            build(o*2,L,M);
            build(o*2+1,M+1,R);
            v[o].sum=v[o*2].sum*v[o*2+1].sum%mod;
            v[o].mul=v[o].pow=1;
        }
    }
    void maintain(int o,int L,int R){
        if(L==R){
            v[o].sum=Pow(a[L],v[o].pow)*v[o].mul%mod;
        }else{
            v[o].sum=Pow(v[o*2].sum*v[o*2+1].sum%mod,v[o].pow)*Pow(v[o].mul,R-L+1)%mod;
        }
    }
    void pushdown(int o){
        v[o*2].pow=v[o*2].pow*v[o].pow%mod2;
        v[o*2].mul=Pow(v[o*2].mul,v[o].pow)*v[o].mul%mod;
        v[o*2+1].pow=v[o*2+1].pow*v[o].pow%mod2;
        v[o*2+1].mul=Pow(v[o*2+1].mul,v[o].pow)*v[o].mul%mod;
        v[o].pow=v[o].mul=1;
    }
    void update(int o,int L,int R,int qL,int qR,ll k,int ty){
        if(qL<=L&&R<=qR){
            if(ty==1) v[o].mul=v[o].mul*k%mod;
            else{
                v[o].pow=v[o].pow*k%mod2;
                v[o].mul=Pow(v[o].mul,k);
            }
        }else{
            int M=(L+R)/2;
            pushdown(o);
            if(qL<=M) update(o*2,L,M,qL,qR,k,ty);
            else maintain(o*2,L,M);
            if(qR>M) update(o*2+1,M+1,R,qL,qR,k,ty);
            else maintain(o*2+1,M+1,R);
        }
        maintain(o,L,R);
    }
    ll query(int o,int L,int R,int qL,int qR){
        if(qL<=L&&R<=qR) return v[o].sum;
        int M=(L+R)/2;
        pushdown(o);
        maintain(o*2,L,M);maintain(o*2+1,M+1,R);
        ll sum=1;
        if(qL<=M) sum*=query(o*2,L,M,qL,qR);
        if(qR>M) sum*=query(o*2+1,M+1,R,qL,qR);
        return sum%mod;
    }
}T;
int main(){
//    freopen("data.txt","r",stdin);
    int ca;
//    IO::begin();
    scanf("%d",&ca);
//    IO::read(ca);
    while(ca--){
        int n,q;
        scanf("%d%d",&n,&q);
//        IO::read(n);IO::read(q);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
//            IO::read(a[i]);
        T.build(1,1,n);
        int op,l,r,k;
        while(q--){
            scanf("%d%d%d",&op,&l,&r);
//            IO::read(op);IO::read(l);IO::read(r);
            if(op<3){
                scanf("%d",&k);
//                IO::read(k);
                T.update(1,1,n,l,r,k,op);
            }else printf("%lld\n",T.query(1,1,n,l,r));
        }
    }
    return 0;
}
/*
1
2 5
1 2
2 1 2 2
1 1 2 2
3 1 2

1
3 5
1 1 1
1 1 3 3
2 1 3 2
1 1 3 2
2 1 3 2
3 1 3
*/

