
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int a[100010];
int c[100010],d[100010];
ll cnt[100010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<p;++i){
            scanf("%d%d",&c[i],&d[i]);
            ++cnt[((d[i]-a[c[i]])%m+m)%m];
        }
        ll ans=0;
        for(int i=0;i<m;++i){
            ans+=cnt[i]*(m-i-1);
        }
        ll now=ans;
        for(int i=0;i<m;++i){
            now-=(m-1)*cnt[i];
            now+=p-cnt[i];
            ans=min(ans,now);
        }
        for(int i=0;i<p;++i){
            --cnt[((d[i]-a[c[i]])%m+m)%m];
        }
        printf("%lld\n",ans);
    }
    return 0;
}

