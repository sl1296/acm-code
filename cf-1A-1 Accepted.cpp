
#include<cstdio>
#define ll long long
int main(){
	ll a,b,c;
	while(~scanf("%lld%lld%lld",&a,&b,&c)){
		printf("%lld\n",((a+c-1)/c)*((b+c-1)/c));
	}
	return 0;
}

