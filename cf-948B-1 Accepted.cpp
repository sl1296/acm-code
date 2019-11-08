
#include<cstdio>
#include<algorithm>
using namespace std;
int f[1000010];
int main(){
	int n,x,ans=n+1;
	scanf("%d",&n);
	for(int i=2;i<=n;++i){
		if(!f[i]){
			if(n%i==0)x=i;
			for(int j=i*2;j<=n;j+=i)f[j]=i;
		}
	}
	for(int i=n-x+1;i<=n;++i)ans=min(ans,i-f[i]+1);
	printf("%d\n",ans);
	return 0;
}

