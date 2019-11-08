
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll c[10010],y[10010];
int main(){
    int n;
    ll s;
    while(~scanf("%d%lld",&n,&s)){
        for(int i=0;i<n;i++){
            scanf("%lld%lld",&c[i],&y[i]);
        }
        ll ans=c[0]*y[0];
        ll pre=c[0]+s;
        for(int i=1;i<n;i++){
            pre=min(pre,c[i]);
            ans+=pre*y[i];
            pre+=s;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

