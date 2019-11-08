
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll a[100010];
ll c[100010],d[100010];
ll ss[100010],sc;
ll cnt[100010],cid[100010],cc;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,p;
        scanf("%lld%lld%lld",&n,&m,&p);
        for(int i=1;i<=n;++i){
            scanf("%lld",&a[i]);
        }
        sc=cc=0;
        for(int i=0;i<p;++i){
            scanf("%lld%lld",&c[i],&d[i]);
            ss[sc++]=((d[i]-a[c[i]])%m+m)%m;
        }
        sort(ss,ss+sc);
        for(int i=0;i<sc;++i){
            cnt[cc]=1;
            while(i+1<sc && ss[i+1]==ss[i]){
                ++i;
                ++cnt[cc];
            }
            cid[cc++]=ss[i];
        }
//        printf("cc=%lld\n",cc);
//        for(int i=0;i<cc;++i){
//            printf("%lld %lld\n",cid[i],cnt[i]);
//        }
        ll ans=0,pre=cid[cc-1];
        for(int i=0;i<cc;++i){
            ans+=cnt[i]*(pre-cid[i]);
        }
//        printf("ans=%lld\n",ans);
        ll now=ans;
        for(int i=0;i<cc;++i){
//            printf("dec%lld %lld\n",((pre-cid[i])%m+m)%m,cnt[i]);
            now-=((pre-cid[i])%m+m)%m*cnt[i];
//            printf("add%lld %lld\n",p-cnt[i],((cid[i]-cid[(i-1+cc)%cc])%m+m)%m);
            now+=((cid[i]-cid[(i-1+cc)%cc])%m+m)%m*(p-cnt[i]);
            ans=min(ans,now);
//            printf("i=%d now=%lld pre=%lld\n",i,now,pre);
            pre=cid[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

