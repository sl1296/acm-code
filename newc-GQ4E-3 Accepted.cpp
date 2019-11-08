
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1<<20;
const int G=3,P=998244353;
ll quick(ll x,ll n){
    ll ret=1;
    for(;n;n>>=1){
        if(n&1)ret=ret*x%P;
        x=x*x%P;
    }
    return ret;
}
ll A[N],B[N];
void rader(ll *y,int len){
    for(int i=1,j=len/2;i<len-1;i++){
        if(i<j)swap(y[i],y[j]);
        int k=len/2;
        while(j>=k){j-=k;k/=2;}
        if(j<k)j+=k;
    }
}
void ntt(ll *y,int len,int op){
    rader(y,len);
    for(int h=2;h<=len;h<<=1){
        ll wn=quick(G,(P-1)/h);
        if(op==-1)wn=quick(wn,P-2);
        for(int j=0;j<len;j+=h){
            ll w=1;
            for(int k=j;k<j+h/2;k++){
                ll u=y[k];
                ll t=w*y[k+h/2]%P;
                y[k]=(u+t)%P;
                y[k+h/2]=(u-t+P)%P;
                w=w*wn%P;
            }
        }
    }
    if(op==-1){
        ll inv=quick(len,P-2);
        for(int i=0;i<len;i++)y[i]=y[i]*inv%P;
    }
}
ll jc[100010];
inline ll C(ll n,ll k){
    return jc[n]*quick(jc[k],P-2)%P*quick(jc[n-k],P-2)%P;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&A[i]);
        B[n-i-1]=A[i];
    }
//    for(int i=0;i<n;++i)printf("%lld ",A[i]);printf("\n");
//    for(int i=0;i<n;++i)printf("%lld ",B[i]);printf("\n");
    int len=1,len1=n,len2=len1;
    while(len<len1*2 || len<len2*2)len<<=1;
    ntt(A,len,1);
    ntt(B,len,1);
    for(int i=0;i<len;i++)A[i]=A[i]*B[i]%P;
    ntt(A,len,-1);
    jc[0]=jc[1]=1;
    for(int i=2;i<n+10;++i)jc[i]=jc[i-1]*i%P;
//    for(int i=0;i<10;++i)printf("%lld ",A[i]);printf("\n");
    ll ans=0;
    for(int i=0;i<n-2;++i){
        ans=(ans+2*C(n,n-i)*jc[n-3-i]%P*jc[i]%P*A[i]%P*(n-2-i)%P)%P;
    }
//    printf("%lld %lld\n",ans,jc[n]);
    ans=ans*quick(jc[n],P-2)%P;
    printf("%lld\n",ans);
    return 0;
}

