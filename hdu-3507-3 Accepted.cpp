
#include<cstdio>
#define ll long long
ll a[500010],dp[500010],sum[500010],qu[500010];
ll gu(int a,int b){
	return dp[a]+sum[a]*sum[a]-dp[b]-sum[b]*sum[b];
}
ll gd(int a,int b){
	return 2*(sum[a]-sum[b]);
}
int main(){
	ll n,m;
	while(~scanf("%lld%lld",&n,&m)){
		dp[0]=0;
		qu[0]=0;
		sum[0]=0;
		int ff=0,tt=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		//	printf("%lld %lld\n",a[i],sum[i]);
		}
		for(int i=1;i<=n;i++){
			while(ff+1<tt&&gu(qu[ff+1],qu[ff])<=sum[i]*gd(qu[ff+1],qu[ff]))ff++;
			dp[i]=dp[qu[ff]]+m+(sum[i]-sum[qu[ff]])*(sum[i]-sum[qu[ff]]);
		//	printf("m=%lld dp[qu=%lld sum1=%lld sum2=%lld\n",m,dp[qu[ff]],sum[i],sum[qu[ff]]);
		//	printf("%d %d %lld %d\n",ff,tt,dp[i],qu[ff]);
			while(ff+1<tt&&gu(qu[tt-1],qu[tt-2])*gd(i,qu[tt-1])>=gu(i,qu[tt-1])*gd(qu[tt-1],qu[tt-2]))tt--;
		//	printf("%d %d %lld\n",ff,tt,dp[i]);
			qu[tt++]=i;
		}
		printf("%lld\n",dp[n]);
	}
	return 0;
}

