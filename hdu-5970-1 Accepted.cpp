
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int f(int x,int y){
    int c=0;
    while(y>0){
        c+=1;
        int t=x%y;
        x=y;
        y=t;
    }
    return c;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,p;
        scanf("%lld%lld%lld",&n,&m,&p);
        ll ans=0;
        for(ll i=1;i<=m;i++){
            for(ll j=1;j<=i;j++){
                ll tc=f(j,i),tx=__gcd(j,i),mul=tx*tx*tc;
                ll num=n/i;
                if(n%i>=j)num++;
                ll tmp=0;
                ll now=j;
                for(ll k=1;k<=tc;k++){
                    tmp+=now*i/mul%p;
                    if(tmp>=p)tmp-=p;
                    now+=i;
                }
                ll cnt=num/tc;
                ll dis=i*i*tc*tc/mul;
                ans+=(tmp+tmp+(cnt-1)*dis)*cnt/2%p;
                if(ans>=p)ans-=p;
                ll ff=(cnt*tc)*i+j;
                for(ll k=cnt*tc+1;k<=num;k++,ff+=i){
                    ans+=ff*i/mul%p;
                    if(ans>=p)ans-=p;
                }
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}

