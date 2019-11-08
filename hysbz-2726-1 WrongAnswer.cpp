
#include<cstdio>
#define ll long long
ll m,n;
ll dp[1000010],time[1000010],t[1000010],f[1000010],p[1000010],qu[1000010];
ll gu(int a,int b){
	return dp[a]-m*p[a]-dp[b]+m*p[b];
}
ll gd(int a,int b){
	return p[a]-p[b];
}
int main(){
	while(~scanf("%lld%lld",&n,&m)){
		dp[0]=0;
		qu[0]=0;
		t[0]=0;
		p[0]=0;
		int ff=0,tt=1;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",&time[i],&f[i]);
			t[i]=t[i-1]+time[i];
			p[i]=p[i-1]+f[i];
		//	printf("%lld %lld\n",a[i],sum[i]);
		}
		for(int i=1;i<=n;i++){
			while(ff+1<tt&&gu(qu[ff+1],qu[ff])<=t[i]*gd(qu[ff+1],qu[ff]))ff++;
			dp[i]=dp[qu[ff]]+m*(p[n]-p[qu[ff]])+t[i]*(p[i]-p[qu[ff]]);
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

