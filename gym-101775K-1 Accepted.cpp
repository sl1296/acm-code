
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll sum[100010],x[100010];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        ll a,b,n;
        scanf("%lld%lld%lld",&a,&b,&n);
        for(int i=1;i<=a;++i){
            scanf("%lld",&x[i]);
            sum[i]=sum[i-1]+x[i];
        }
        ll pa=a,pb=b,na=a,nb=b;
        for(int i=0;i<n;++i){
            int pos=lower_bound(sum+1,sum+1+a,na)-sum;
            nb=x[pos]-sum[pos]+na;
            na=pos;
            if(na==pa && nb==pb)break;
            pa=na;pb=nb;
        }
        printf("Case #%d: %lld-%lld\n",z,na,nb);
    }
    return 0;
}

