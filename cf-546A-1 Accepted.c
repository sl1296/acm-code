
#include <stdio.h>
int main(){
	int  k,n,w,x;
	while(scanf("%d%d%d",&k,&n,&w)!=EOF){
	x=w*(w+1)/2*k;
	if(x>n)printf("%d\n",x-n);
	else printf("0\n");
}
	return 0;
}

