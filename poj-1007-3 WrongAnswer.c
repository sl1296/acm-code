
#include <stdio.h>
int main()
{
	int i,a,b,j,n,k,l;
	char c[110][110],h[110];
	int d[60];
	int m;
	scanf("%d%d",&b,&a);
	for(i=0;i<a;i++)
	{
	n=0;
	scanf("%s",c[i]);
	for(j=0;j<b-1;j++)
	{
	for(k=j+1;k<b;k++)
	{
	if(c[i][j]>c[i][k])n++;
	}
	}
	d[i]=n;
	}
	for(i=0;i<a-1;i++)
	{
	for(j=i+1;j<a;j++)
	{
	if(d[i]>d[j])
	{
	m=d[i];
	d[i]=d[j];
	d[j]=m;
	for(l=0;l<=b;l++)
	{
	h[l]=c[j][l];
	c[j][l]=c[i][l];
	c[i][l]=h[l];
	}
	}
	}
	}
	for(i=0;i<=a-1;i++)
	{
	printf("%s\n",c[i]);
	}
	return 0;
}

