
#include <stdio.h>
#include <math.h>
int main(){
	int t,i,n,out;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		switch(n){
			case 0:
			case 1:
				out=1;
				break;
			default:
				out=ceil(log10(2*3.1415926535897932*n)/2+n*(log10(n)-log10(2.7182818284590452)));
		}
		printf("%d\n",out);
	}
	return 0;
}

