
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll v[100010],t[100010],sum[100010],sz[100010],add[100010];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&v[i]);
	for(int i=1;i<=n;++i){
		scanf("%lld",&t[i]);
		sum[i]=sum[i-1]+t[i];
	}
	int cnt=0;
	for(int i=1;i<=n;++i){
		++sz[i];
		int pos=lower_bound(sum+i,sum+n+1,v[i]+sum[i-1])-sum;
		--sz[pos];
		add[pos]+=v[i]+sum[i-1]-sum[pos-1];
		cnt+=sz[i];
		printf("%lld%c",add[i]+cnt*t[i],i==n?'\n':' ');
	}
	return 0;
}


