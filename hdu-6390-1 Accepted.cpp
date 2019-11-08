
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
int tot,mu[1000010],pri[1000010],s[1000010];
bool mark[1000010];
int euler[1000010];
ll sum[1000010],inv[1000010];
ll mod;
inline ll f(ll x,ll y){
    ll ans=0,last;
    for(ll i=1;i<=min(x,y);i=last+1){
        last=min(x/(x/i),y/(y/i));
//        printf("f:i=%lld last=%lld s:%d x/i=%lld y/i=%lld\n",i,last,s[last]-s[i-1],x/i,y/i);
        ans=(ans+(s[last]-s[i-1])*(x/i)%mod*(y/i)%mod)%mod;
//        printf("ans=%lld\n",ans);
    }
    return ans;
}
inline void init(ll N){
//    printf("init N=%lld\n",N);
    tot=0;
    memset(mu,0,sizeof(mu));
    memset(pri,0,sizeof(pri));
    memset(s,0,sizeof(s));
    memset(mark,false,sizeof(mark));
    mu[1]=1;
    for(int i=2;i<=N;++i){
        if(!mark[i])pri[++tot]=i,mu[i]=-1;
        for(int j=1;j<=tot&&pri[j]*i<=N;++j){
            mark[pri[j]*i]=1;
            if(i%pri[j]==0){
                mu[pri[j]*i]=0;
                break;
            }else{
                mu[pri[j]*i]=-mu[i];
            }
        }
    }
    for(int i=1;i<=N;++i){
        s[i]=(s[i-1]+mu[i])%mod;
//        printf("i=%d mu[i]=%d s[i]=%d\n",i,mu[i],s[i]);
    }
    inv[0]=inv[1]=1;
    for(int i=2;i<=N;++i){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
//        printf("i=%d inv[i]=%lld\n",i,inv[i]);
    }
    for(int i=1;i<=N;++i){
        sum[i]=(sum[i-1]+i*inv[euler[i]]%mod)%mod;
//        printf("i=%d sum[i]=%lld\n",i,sum[i]);
    }
}
int main(){
    for(int i=1;i<1000001;i++)euler[i]=i;
    for(int i=2;i<1000001;i++)if(euler[i]==i)for(int j=i;j<1000001;j+=i)euler[j]=euler[j]/i*(i-1);
    int t;
    scanf("%d",&t);
    while(t--){
        ll m,n,p;
        scanf("%lld%lld%lld",&m,&n,&mod);
        init(min(m,n));
        ll last,ans=0;
        for(ll d=1;d<=min(m,n);d=last+1){
            last=min(n/(n/d),m/(m/d));
//            printf("main d=%lld last=%lld sum:%lld\n",d,last,sum[last]-sum[d-1]);
            ans=(ans+(sum[last]-sum[d-1]+mod)%mod*f(n/d,m/d)%mod)%mod;
//            printf("ans=%lld\n",ans);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
10
2515 145 1000000007
641 4584 1000000007
341305605
311331088
*/

