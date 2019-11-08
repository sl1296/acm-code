
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int main(){
	ll n;
	bool x[15];
	while(~scanf("%lld",&n)){
		memset(x,false,sizeof(x));
		int ans=0;
		for(ll i=n;;i+=n){
			ans++;
			ll t=i;
			while(t){
				x[t%10]=true;
				t/=10;
			}
			bool pd=true;
			for(int j=0;j<10;j++)if(!x[j]){pd=false;break;}
			if(pd)break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
/**********************************************************************
	Problem: 2064
	User: asdcvbn
	Language: C++
	Result: AC
	Time:0 ms
	Memory:1120 kb
**********************************************************************/

