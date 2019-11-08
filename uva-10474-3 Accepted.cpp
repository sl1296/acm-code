
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10010];
int main(){
	int n,m,cas=1;
	while(~scanf("%d%d",&n,&m)){
		if(n==0&&m==0)break;
		for(int i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,a+n);
		printf("CASE# %d:\n",cas++);
		for(int i=0;i<m;i++){
			int q;
			scanf("%d",&q);
			int r=lower_bound(a,a+n,q)-a;
			if(a[r]==q){
				printf("%d found at %d\n",q,r+1);
			}else{
				printf("%d not found\n",q);
			}
		}
	}
	return 0;
}

