
#include<cstdio>
#define ll long long
const ll mod= 998244353;
ll p2[10000010]={1};
int main(){
    for(int i=1;i<10000005;++i){
        p2[i]=p2[i-1]+p2[i-1];
        if(p2[i]>=mod)p2[i]-=mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ll now=0;
        if(b>1 && c>0){
            ll ka=p2[b]-1-b;
            if(ka<0)ka+=mod;
            ll kb=p2[c]-1;
            if(kb<0)kb+=mod;
            now=ka*kb%mod*p2[a]%mod;
        }
        if(d>0 && d+b>1){
            ll ka=p2[b+d]-1-b-d;
            if(ka<0)ka+=mod;
            ll kb=0;
            if(b>1){
                kb=p2[b]-1-b;
                if(kb<0)kb+=mod;
            }
            ka-=kb;
            if(ka<0)ka+=mod;
            now+=ka*p2[a+c]%mod;
            if(now>=mod)now-=mod;
        }
        now=p2[a+b+c+d]-now;
        if(now<0)now+=mod;
        printf("%lld\n",now);
    }
    return 0;
}

