
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
ll a[100010],jc[100010];
int main(){
    jc[0]=jc[1]=1;
    for(int i=2;i<100010;++i){
        jc[i]=jc[i-1]*i%P;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        B[i]=A[i]=a[i]*jc[i]%P;
    }
    int len=1,len1=n,len2=len1;
    while(len<len1*2 || len<len2*2)len<<=1;
    ntt(A,len,1);
    ntt(B,len,1);
    for(int i=0;i<len;i++)A[i]=A[i]*B[i]%P;
    ntt(A,len,-1);
    for(int i=0;i<n;++i){
        if(i)printf(" ");
        ll b=quick(2,i)*A[n-1+i]%P*quick(jc[i],P-2)%P;
        printf("%lld",b);
    }
    printf("\n");
    return 0;
}

