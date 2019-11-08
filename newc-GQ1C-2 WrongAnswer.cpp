
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
int main(){
    ll x,y,a,b,c,p1,p2,q1,q2;
    scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&p1,&p2,&q1,&q2);
    ll gcd=exgcd(a,b,x,y);
    if(c%gcd){
        printf("Kuon\n");
    }else{
        ll lcm=a/gcd*b;
        ll ka=lcm/a;
        ll kb=lcm/b;
        ll mu=c/gcd;
        x*=mu;y*=mu;
        ll ra=p2*ka*ka+q2*kb*kb;
        ll rb=2*x*ka*p2-2*y*kb*q2+p1*ka-q1*kb;
        ll rc=p2*x*x+q2*y*y+p1*x+q1*y;
//        printf("%lld %lld %lld\n",ra,rb,rc);
        ll rx=-rb/(2*ra);
        ll ans=rx*rx*ra+rx*rb+rc;
        for(int i=-20;i<20;++i){
            ll tx=rx+i;
            ans=min(ans,tx*tx*ra+tx*rb+rc);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

