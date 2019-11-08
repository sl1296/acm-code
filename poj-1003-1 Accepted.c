
#include <stdio.h>
int main()
{
	double x,y;
	int i;
	while(1)
	{
		y=0;
		scanf("%lf",&x);
		if(!x)break;
		for(i=2;y<x;i++)y+=(1.0/i);
		printf("%d card(s)\n",i-2);
	}
	return 0;
}

