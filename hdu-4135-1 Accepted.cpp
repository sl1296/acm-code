
#include<cstdio>
#define ll long long
int ys[50],ysn;
ll a,b;
int n;
ll cal(ll x){
    ll ans=0;
    for(int i=1;i<(1<<ysn);i++){
        int bs=1;
        int cnt=0;
        for(int j=0;j<ysn;j++){
            if(i&(1<<j)){
                cnt++;
                bs=bs*ys[j];
            }
        }
        cnt=cnt&1?1:-1;
        ans=ans+x/bs*cnt;
    }
    return x-ans;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        ysn=0;
        scanf("%lld%lld%d",&a,&b,&n);
        int tmp=n;
        for(int i=2;i*i<=n;i++){
            if(tmp%i==0){
                ys[ysn++]=i;
                do{
                    tmp/=i;
                }while(tmp%i==0);
            }
        }
        if(tmp>1)ys[ysn++]=tmp;
        ll ans=cal(b)-cal(a-1);
        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}

