
#include<cstdio>
#define ll long long
ll a[300010];
ll num[300010];
ll cnt[300010];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    num[0]=1;
    int nc=0;
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;++i){
        if((double)a[i]*num[i-1]>1e13)break;
        num[i]=num[i-1]*a[i];
        ++nc;
    }
    cnt[1]=1;
    for(int i=2;i<=nc;++i){
        cnt[i]=cnt[i-1]*a[i]+1;
    }
    while(m--){
        ll x;
        scanf("%lld",&x);
        if(x==0){
            printf("0\n");
        }else{
            ll ans=n-nc;
            for(int i=nc;i>0;--i){
                ll cc=x/num[i];
                ans+=cc*cnt[i];
                x%=num[i];
                if(x)++ans;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

