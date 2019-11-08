
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1000000007;
int a[1010];
ll c[2050][2050];
int main(){
    int k;
    for(int i=0;i<=2010;i++)c[i][0]=1;
    for(int i=1;i<2010;i++)for(int j=1;j<2010;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    while(scanf("%d",&k)!=EOF){
        ll ans=1;
        for(int i=0;i<k;i++){
            scanf("%d",&a[i]);
        }
        ll num=a[0];
        for(int i=1;i<k;i++){
            ans=ans*c[a[i]-1+num][num]%mod;
            num+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

