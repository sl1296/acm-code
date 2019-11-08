
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
    if(a==0&&b==0){
        if(c==0){
            ll ans1=0,ans2=0;
            ll x1=-p1/(2*p2);
            for(int i=-20;i<20;i++){
                ll nx=x1+i;
                ans1=min(ans1,nx*nx*p2+nx*p1);
            }
            ll x2=-q1/(2*q2);
            for(int i=-20;i<20;i++){
                ll nx=x2+i;
                ans2=min(ans2,nx*nx*q2+nx*q1);
            }
            printf("%lld\n",ans1+ans2);
        }
        else printf("Kuon\n");
        return 0;
    }else if(a==0||b==0){
        if(a==0){
            swap(a,b);
            swap(p1,q1);
            swap(p2,q2);
        }
        if(c%a) printf("Kuon\n");
        else{
            ll x1=c/a;
            ll ans1=p2*x1*x1+p1*x1,ans2=0;
            ll x2=-q1/(2*q2);
            for(int i=-20;i<20;i++){
                ll nx=x2+i;
                ans2=min(ans2,nx*nx*q2+nx*q1);
            }
            printf("%lld\n",ans1+ans2);
        }
        return 0;
    }
    ll gcd=exgcd(a,b,x,y);
    if(c%gcd){
        printf("Kuon\n");
    }else{
        ll ans=1e18;
        ll rx=(2*p2*b*c+p1*b*a-q1*a*a)/(2*p2*b*b+2*a*a*q2);
        for(int i=-1000000;i<1000000;i++){
            ll y=rx+i;
            if((c-b*y)%a!=0) continue;
            ll x=(c-b*y)/a;
            ans=min(ans,p2*x*x+p1*x+q2*y*y+q1*y);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

