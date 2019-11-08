
#include <stdio.h>
#include <math.h>
int main()
{
	double x,y;
	int t,i,s;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lf%lf",&x,&y);
		s=ceil((x*x+y*y)*atan(1.0)/25);
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,s);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}

