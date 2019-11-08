
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mu[20000001],pri[20000001],sum[20000001];
bool mark[20000001];
int tot;
int main(){
    mu[1]=1;
    for(int i=2;i<20000001;++i){
        if(!mark[i]){mu[i]=-1;pri[++tot]=i;}
        for(int j=1;j<=tot&&i*pri[j]<20000001;++j){
            mark[i*pri[j]]=1;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else mu[i*pri[j]]=-mu[i];
        }
    }
    sum[1]=mu[1];
    for(int i=2;i<20000001;++i)sum[i]=sum[i-2]+mu[i];
    int t;
    ll n;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ll ans=0;
        ll pos,cnt;
//        ll ret=0;
        for(ll i=1;i<n;i=pos+1){
            pos=min(n/(n/i),(n-1)/((n-1)/i));
            if(pos&1)++pos;
//            printf("i=%lld pos=%lld %lld %lld\n",i,pos,n/(n/i),(n-1)/((n-1)/i));
            cnt=(n-1)/i;
            ans+=(n/i*cnt-cnt*(cnt+1)/2)*(sum[pos-1]-(i>1?sum[i-2]:0));
//            for(ll j=i;j<=pos;j+=2){
//                cnt=(n-1)/j;
//                printf("j=%lld cnt=%lld add=%lld m=%lld\n",j,cnt,(n/j*cnt-cnt*(cnt+1)/2),mu[j]);
//                ret+=(n/j*cnt-cnt*(cnt+1)/2)*mu[j];
//            }
//            printf("ans=%lld ret=%lld\n",ans,ret);
        }
//        printf("1\n");
        for(ll i=2;i<n;i=pos+1){
            pos=min(n/(n/(i/2))*2,(n-1)/((n-1)/i));
            if(!(pos&1))++pos;
//            printf("i=%lld pos=%lld %lld %lld\n",i,pos,n/(n/(i/2)),(n-1)/((n-1)/i));
            cnt=(n-1)/i;
            ans+=(n/(i/2)*cnt-cnt*(cnt+1))*(sum[pos-1]-sum[i-2]);
//            printf("%lld %lld\n",n/(i/2)*cnt-cnt*(cnt+1),sum[pos-1]-sum[i-2]);
//            for(ll j=i;j<=pos;j+=2){
//                printf("j=%lld cnt=%lld n/(j/2)=%lld\n",j,cnt,n/(j/2));
//                cnt=(n-1)/j;
//                ret+=((n/(j/2))*cnt-cnt*(cnt+1))*mu[j];
//                printf("%lld %lld\n",mu[j],(n/(j/2))*cnt-cnt*(cnt+1));
//            }
//            printf("ans=%lld ret=%lld\n",ans,ret);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

