
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
char in[10010];
int tree[100010];
int n;
int lowbit(int x){
	return x&(-x);
}
void update(int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))tree[i]+=v;
}
int query(int x){
	int r=0;
	for(int i=x;i;i-=lowbit(i))r+=tree[i];
	return r;
}
int main(){
	int x;
	while(1){
		long long ans=0;
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		if(!n)break;
		map<string,int> ma;
		for(int i=1;i<=n;i++){
			scanf("%s",in);
			ma[in]=i;
		}
		for(int i=0;i<n;i++){
			scanf("%s",in);
			x=ma[in];
			update(x,1);
			ans+=(i+1-query(x));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

