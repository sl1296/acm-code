
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll zs[100010],zsc;
int a[100010],b[100010];
ll fj[50],fjc;
int main(){
    for(ll i=2;i<100005;++i){
        if(!zs[i]){
            for(ll j=i*i;j<100005;j+=i){
                zs[j]=1;
            }
        }
    }
    for(int i=2;i<100005;++i){
        if(!zs[i]){
            zs[zsc++]=i;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        fjc=0;
        scanf("%d",&n);
        ll sum=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        for(int i=0;zs[i]*zs[i]<=sum;++i){
            if(sum%zs[i]==0){
                fj[fjc++]=zs[i];
                while(sum%zs[i]==0)sum/=zs[i];
            }
        }
        if(sum>1)fj[fjc++]=sum;
        ll ans=1LL<<62;
        for(int i=0;i<fjc;++i){
            sum=0;
            for(int j=0;j<n;++j){
                b[j]=a[j]%fj[i];
                sum+=b[j];
            }
            sort(b,b+n);
            sum/=fj[i];
            ll tmp=0;
            for(int j=0;j<n-sum;++j){
                tmp+=b[j];
            }
            ans=min(ans,tmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

