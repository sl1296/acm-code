
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
        ll ans=1e18;
        ll rx=0;
        for(int i=-10000000;i<10000000;i++){
            ll y=rx+i;
            if((c-b*y)%a!=0) continue;
            ll x=(c-b*y)/a;
            ans=min(ans,p2*x*x+p1*x+q2*y*y+q1*y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

