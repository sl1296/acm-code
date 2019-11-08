
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll c(ll a,ll b){
	ll ret=1;
	for(ll i=1;i<=b;i++){
		ret=ret*(a-i+1)/i;
	}
	return ret;
}
ll dp[70][3];
int main(){
	dp[0][0]=1;
	for(int i=1;i<63;i++){
		for(int j=0;j<=i;j++){
			dp[i][j%3]+=c(i,j);
		}
	}
	ll n;
	while(~scanf("%lld",&n)){
		ll ans=-1;
		int cnt=0,cc=1;
		for(int i=62;i>=0;i--){
			if(n&(1LL<<i)){
				cnt=i+1;
				break;
			}
		}
		if(cnt)ans+=dp[cnt-1][0];else ans=0;
		for(int i=cnt-2;i>0;i--){
			if(n&(1LL<<i)){
				ans+=dp[i][(3-cc%3)%3];
				cc++;
			}
		}
		if(cc%3==0)ans++;
		if(n&1 && cc%3==2)ans++;
		printf("Day %lld: Level = %lld\n",n,ans);
	}	
	return 0;
}
/**********************************************************************
	Problem: 2069
	User: asdcvbn
	Language: C++
	Result: AC
	Time:0 ms
	Memory:1120 kb
**********************************************************************/



