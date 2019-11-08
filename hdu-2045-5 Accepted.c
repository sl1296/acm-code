
#include <stdio.h>
#include <math.h>
int main(){
	__int64 a[60];
	int n,i;
	a[1]=3;
	a[2]=a[3]=6;
	for(i=4;i<51;i++)a[i]=a[i-1]+2*a[i-2];
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",a[n]);
	}
	return 0;
}

