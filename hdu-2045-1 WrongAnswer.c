
#include <stdio.h>
#include <math.h>
int main(){
	int n,i;
	int a[55];
	a[1]=3;a[2]=6;a[3]=6;
	for(i=4;i<51;i++)a[i]=pow(2,i-1)*3-a[i-1];
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",a[n]);
	}
}

