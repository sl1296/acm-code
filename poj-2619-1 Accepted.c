
#include <stdio.h>
#include <math.h>
int main(){
	long m,n,m1,n1,m2,n2,p,q,i,j,t;
scanf("%d%d",&m,&n);
	if(m>n){t=m;m=n;n=t;}
	m1=ceil(sqrt(m));
	n1=ceil(sqrt(n));
	m2=ceil(sqrt(m));
	m2*=m2;
	m2-=m;
	n2=ceil(sqrt(n));
	n2*=n2;
	n2-=n;
	i=(m1+m)%2;
		j=(n1+n)%2;
			p=m2;
	q=m2+2*(n1-m1);
	if(n2<p)n2=p-n2;
		else if(n2>q)n2=n2-q;
		else n2=i-j;
		printf("%d",2*(n1-m1)+n2);
	return 0;
}

