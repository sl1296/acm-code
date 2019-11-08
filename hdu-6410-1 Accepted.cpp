
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e9+7;
int l[10010],r[10010];
int sum[101][10010];
ll inv(ll a,ll n){
    if(a==1)return 1;
    return inv(n%a,n)*(n-n/a)%n;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,mi=0,mx=0;
        scanf("%d",&n);
        ll div=1;
        for(int i=0;i<n;++i){
            scanf("%d%d",&l[i],&r[i]);
            mx=max(mx,r[i]);
            mi=max(mi,l[i]);
            sum[i][l[i]]=l[i];
            for(int j=l[i]+1;j<=r[i];++j)sum[i][j]=sum[i][j-1]+j;
            div=div*(r[i]-l[i]+1)%mod;
        }
        ll ans=0;
        for(int i=mi;i<=mx;++i){
            ll tmp=1,tmp2=1;
            for(int j=0;j<n;++j){
                ll en=min(i,r[j]),cnt=en-l[j]+1;
                ll add=(i*cnt-sum[j][en]+cnt)%mod;
                if(add<0)add+=mod;
                tmp=tmp*add%mod;
                if(i>mi){
                    en=min(i-1,r[j]),cnt=en-l[j]+1;
                    add=(i*cnt-sum[j][en]+cnt)%mod;
                    if(add<0)add+=mod;
                    tmp2=tmp2*add%mod;
                }
            }
            if(i>mi){
                tmp-=tmp2;
                if(tmp<0)tmp+=mod;
            }
            ans+=tmp;
            if(ans>=mod)ans-=mod;
        }
        ans=ans*inv(div,mod)%mod;
        printf("%I64d\n",ans);
    }
    return 0;
}

