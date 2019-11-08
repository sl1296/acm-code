
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
	for(int i=1;i<63;i++){
		for(int j=0;j<=i;j++){
			dp[i][j%3]+=c(i,j);
		}
	}
	ll n;
	while(~scanf("%d",&n)){
		ll tmp=n,ans=0;
		int cnt=0;
		while(tmp){
			tmp>>=1;
			cnt++;
		}
		
	}	
	return 0;
}
/**********************************************************************
	Problem: 2069
	User: asdcvbn
	Language: C++
	Result: WA
**********************************************************************/


