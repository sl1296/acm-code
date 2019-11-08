
#include <stdio.h>
int main()
{
	double x,y=0;
	int i;
	for(i=0;i<12;i++)
	{
		scanf("%lf",&x);
		y+=x;
	}
	printf("$%.2f\n",y/12);
	return 0;
}

