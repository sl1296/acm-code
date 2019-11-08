
#include<cstdio>
int main(){
	long long a,b;
	while(scanf("%I64d%I64d",&a,&b)!=EOF){
		long long c=a/b;
		if(c&1)printf("YES\n");else printf("NO\n");
	}
	return 0;
}

