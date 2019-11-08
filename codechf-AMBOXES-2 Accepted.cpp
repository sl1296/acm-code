
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll a[300010],b[300010];
ll num[300010];
ll cnt[300010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    num[0]=1;
    ll nc=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    ll nn=1;
    for(int i=1;i<=n;++i){
        b[nn]=1;
        if(a[i]!=1){
            a[nn++]=a[i];
        }else{
            while(i+1<=n && a[i+1]==1){
                ++i;
                ++b[nn];
            }
            a[nn++]=1;
        }
    }
    --nn;
    ll open=0;
    for(int i=1;i<=nn;++i){
        if((double)a[i]*num[i-1]>1e13)break;
        num[i]=num[i-1]*a[i];
        ++nc;
        open+=b[i];
    }
    cnt[1]=b[1];
    for(int i=2;i<=nc;++i){
        cnt[i]=cnt[i-1]*a[i]+b[i];
    }
//    printf("nn=%lld nc=%lld open=%lld\n",nn,nc,open);
//    for(int i=1;i<=nn;++i){
//        printf("%lld %lld\n",a[i],b[i]);
//    }
    while(m--){
        ll x;
        scanf("%lld",&x);
        if(x==0){
            printf("0\n");
        }else{
            ll ans=n-open;
//            printf("ans=%lld\n",ans);
            for(int i=nc;i>0;--i){
                ll cc=x/num[i];
                ans+=cc*cnt[i];
                x%=num[i];
//                printf("cc=%lld ans=%lld x=%lld\n",cc,ans,x);
                if(x)ans+=b[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

