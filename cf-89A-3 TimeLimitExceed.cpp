
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
    ll n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        ll mx=99999999;
        for(int i=0;i<n;i++){
            ll a;
            scanf("%d",&a);
            if(i%2==0)mx=min(mx,a);
        }
        if(n&1){
            ll op=(n+1)/2;
            ll cnt=min(m/op*k,mx);
            printf("%lld\n",cnt);
        }else{
            printf("0\n");
        }
    }
    return 0;
}

