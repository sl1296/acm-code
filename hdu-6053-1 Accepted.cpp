
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
bool check[100010];
int mu[100010];
int prime[100010];
int x[200010];
void Moblus(){
    memset(check,false,sizeof(check));
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=100010;i++){
        if(!check[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++){
            int tmp=i*prime[j];
            if(tmp>100010)break;
            check[tmp]=true;
            if(i%prime[j]==0){
                mu[tmp]=0;
                break;
            }else{
                mu[tmp]=-mu[i];
            }
        }
    }
}
ll quickpow(ll m,ll n){
    ll b=1;
    while(n){
        if(n&1)b=(b*m)%mod;
        n>>=1;
        m=(m*m)%mod;
    }
    return b;
}
int main(){
    Moblus();
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(x,0,sizeof(x));
        int n;
        scanf("%d",&n);
        int mx=-9999999,mi=9999999;
        for(int i=0;i<n;i++){
            int a;
            scanf("%d",&a);
            x[a]++;
            mx=max(mx,a);
            mi=min(mi,a);
        }
        ll ans=0;
        for(int i=mx-1;i>=0;i--)x[i]+=x[i+1];
        for(int i=2;i<=mi;i++){
            ll r=-mu[i];
            if(r==0)continue;
            int p=i,cnt=1;
            for(;p<=mx;p+=i,cnt++){
                r=r*quickpow(cnt,x[p]-x[p+i])%mod;
            }
            ans=(ans+r+mod)%mod;
        }
        printf("Case #%d: %lld\n",z,(ans+mod)%mod);
    }
    return 0;
}

