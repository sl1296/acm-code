
#include<cstdio>
#include<cstring>
#define ll long long
const ll mod=1e9+7;
ll jc[200010],invjc[200010],inv[200010],q1_4[200010];
inline ll C(int n,int k){
    return jc[n]*invjc[k]%mod*invjc[n-k]%mod;
}
int main(){
    inv[0]=inv[1]=1;
    jc[0]=jc[1]=1;
    invjc[0]=invjc[1]=1;
    for(int i=2;i<200010;++i){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        jc[i]=jc[i-1]*i%mod;
        invjc[i]=invjc[i-1]*inv[i]%mod;
    }
    q1_4[0]=1;
    q1_4[1]=inv[4];
    for(int i=2;i<200010;++i){
        q1_4[i]=q1_4[i-1]*q1_4[1]%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(m<0)m=-m;
        if(m>n){
            printf("0\n");
        }else{
            ll ans=C(2*n,m+n)*q1_4[n]%mod;
            printf("%lld\n",ans);
        }
    }
}

