
#include <stdio.h>
int main(){
	int i,n,a,l,c;
	while(1){
		c=a=0;
		scanf("%d",&n);
		if(!n)break;
		for(i=0;i<n;i++){
			scanf("%d",&l);
			c+=((a-l)*(a-l>0?4:-6)+5);
			a=l;
		}
		printf("%d\n",c);
	}
	return 0;
}

