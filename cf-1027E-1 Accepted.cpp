
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=998244353;
ll dpa[510][510];
ll dpr[510],dpx[510];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i){
        ll sum=0;
        dpa[1][1]=1;
        for(int j=2;j<=i;++j)dpa[1][j]=0;
        for(int j=2;j<=n;++j){
            dpa[j][1]=dpa[j-1][1];
            for(int k=2;k<=i;++k){
                dpa[j][k]=dpa[j-1][k-1];
                dpa[j][1]+=dpa[j-1][k];
                if(dpa[j][1]>=mod)dpa[j][1]-=mod;
            }
        }
        for(int j=1;j<=i;++j){
            sum+=dpa[n][j];
            if(sum>=mod)sum-=mod;
        }
        dpx[i]=sum;
        sum+=sum;
        if(sum>=mod)sum-=mod;
        dpr[i]=sum;
    }
    ll ans=0;
    for(int i=1;i<k&&i<=n;++i){
        ll mx=min((k-1)/i,n);
//        printf("mx=%I64d\n",mx);
        ll ka=dpr[i]-dpr[i-1]+mod;
        if(ka>=mod)ka-=mod;
        ll kb=dpx[mx];
        ans=(ans+ka*kb%mod)%mod;
//        printf("ka=%I64d kb=%I64d ans=%I64d\n",ka,kb,ans);
    }
    printf("%I64d\n",ans);
}

