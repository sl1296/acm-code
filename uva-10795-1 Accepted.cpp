
//adtm
#include<cstdio>
#define ll long long
using namespace std;
int s[70],t[70];
ll x(int *p,int f,int oth){
	if(f==-1)return 0;
	if(p[f]==oth)return x(p,f-1,oth);
	return x(p,f-1,6-p[f]-oth)+(1LL<<f);
}
int main(){
	int cas=1;
	while(1){
		int n;
		scanf("%d",&n);
		if(!n)break;
		for(int i=0;i<n;i++)scanf("%d",&s[i]);
		for(int i=0;i<n;i++)scanf("%d",&t[i]);
		int f=n-1;
		while(f>-1 && s[f]==t[f])f--;
		ll ans=0;
		if(f>-1){
			int oth=6-s[f]-t[f];
			ans=x(s,f-1,oth)+x(t,f-1,oth)+1;
		}
		printf("Case %d: %lld\n",cas,ans);cas++;
	}
	return 0;
}

