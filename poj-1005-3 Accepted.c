
#include <stdio.h>
#include <math.h>
int main(){
	double u,v;
	int n,i,re;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf%lf",&u,&v);
		re=ceil((u*u+v*v)*3.1415926535897932/100);
		printf("Property %d: This property will begin eroding in year %d.\n",i,re);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}

