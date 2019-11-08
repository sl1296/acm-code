
#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
ll a[1000010];
ll c[1000010];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        ll sum=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        ll avg=sum/n;
        c[0]=0;
        for(int i=1;i<n;i++){
            c[i]=c[i-1]+a[i]-avg;
        }
        sort(c,c+n);
        ll pos=c[n/2];
        ll ans=0;
        for(int i=0;i<n;i++)
            ans+=abs(pos-c[i]);
        printf("%lld\n",ans);
    }
    return 0;
}

