
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
#define ll long long
set<ll> a,b,ans;
int main(){
    int n;
    ll x;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&x);
        b.insert(x);
        for(ll j:a)b.insert(__gcd(x,j));
        for(ll j:b)ans.insert(j);
        a=b;
        b.clear();
    }
    printf("%u\n",ans.size());
    return 0;
}

