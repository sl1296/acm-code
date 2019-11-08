
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL inv[2000010]={1,1};
LL c(LL n,LL k){
    if(k>n-k)k=n-k;
    LL r=1;
    for(LL i=1;i<=k;i++)r=r*(n-i+1)%mod*inv[i]%mod;
    return r;
}
LL quickpow(LL m,LL n,LL mod){
    LL b=1;
    while(n){
        if(n&1)b=(b*m)%mod;
        n>>=1;
        m=(m*m)%mod;
    }
    return b;
}
LL invf(LL a,LL n){
    if(a==1)return 1;
    return invf(n%a,n)*(n-n/a)%n;
}
LL ys[1000],ysn,ysc[1000],f[1000],ysx[1000];
LL fi[2000010]={0,1};
int main(){
    for(int i=2;i<2000009;++i){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        fi[i]=fi[i-1]+fi[i-2];
        if(fi[i]>=mod)fi[i]-=mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,k;
        scanf("%lld%lld",&n,&k);
        LL ff=c(n+k-1,k);
        ysn=0;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                ys[ysn++]=i;
                if(i*i<n)ys[ysn++]=n/i;
            }
        }
        sort(ys,ys+ysn);
        for(int i=0;i<ysn;++i){
            ysx[i]=n/ys[i];
            ysc[i]=c(ys[i]+k-1,k-1);
//            printf("%lld %d\n",ys[i],k);
//            printf("c %lld %d\n",ys[i]+k-1,k-1);
            f[i]=quickpow(2,fi[ysx[i]],mod)-1;
            if(f[i]<0)f[i]+=mod;
//            printf("%lld %lld %lld\n",ys[i],ysc[i],f[i]);
        }
        LL ans=0,div=ysc[ysn-1];
        for(int i=0;i<ysn;++i){
            for(int j=i-1;j>=0;--j){
                if(ysx[j]%ysx[i]==0){
                    ysc[i]-=ysc[j];
                    if(ysc[i]<0)ysc[i]+=mod;
                }
            }
//            printf("%lld(%lld) %lld\n",ys[i],ysx[i],ysc[i]);
            ans+=ysc[i]*f[i]%mod;
//            printf("%lld\n",ans);
            if(ans>=mod)ans-=mod;
        }
//        printf("%lld %lld\n",ysc[ysn-1],invf(ysc[ysn-1],mod));
        ans=ans*invf(div,mod)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
01 02 03 05 06 10 15 30
30 15 10  6  5  3  2  1
 8  8  4  2  4  2  1  1
*/

