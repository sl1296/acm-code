
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1000000007;
int a[1010];
ll c(ll n,ll k)
{
    ll i,r=1;
    for(i=1;i<=k;i++)r=r*(n-i+1)/i;
    return r;
}
int main(){
    int k;
   // printf("%lld",c(5,3));
    while(scanf("%d",&k)!=EOF){
        ll ans=1;
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        ll num=a[0];
        for(int i=1;i<k;i++){
            ans=ans*c(a[i]-1+num,num)%mod;
            num+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

