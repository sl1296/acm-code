
#include <stdio.h>
int main(){
	int i,l,m,n,t,l2,m2,n2;
	for(i=0;;i++){
		scanf("%d%d%d%d",&l,&m,&n,&t);
		if(l==-1 && m==-1 && n==-1 && t==-1)break;
	l2=l+23;m2=m+28;n2=n+33;
	a:
	for(;l2<m2;l2+=23);
	for(;m2<n2;m2+=28);
	for(;n2<l2;n2+=33);
	if(l2!=m2 || l2!=n2 || m2!=n2)goto a;
	if(l2<t)l2=21252+l2;
	else if(l2-t>21252)l2=l2-21252;
	printf("Case %d: the next triple peak occurs in %d days.\n",i+1,l2-t);
	}
	return 0;
}

