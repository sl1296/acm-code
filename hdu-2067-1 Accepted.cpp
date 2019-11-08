
#include<iostream>
#include<cmath>
#include<string>
#include<string.h>
#include<map>
#include<stdio.h>
#include<algorithm>
using namespace std;
__int64 kta[36];
int main()
{
	 kta[0]=kta[1]=1;
	int i,j;
	__int64 sum=0;
	for( i=2;i<=35;i++)
	{
		sum=0;
		for( j=0;j<i;j++)
		{
			sum+=(kta[j]*kta[i-j-1]);
		}
		kta[i]=sum;
	}
	int n;
	int flag=1;
	while(cin>>n)
	{
		if(n==-1)
			break;
		printf("%d %d %I64d\n",flag,n,kta[n]*2);
		flag++;
	}
	return 0;
}

