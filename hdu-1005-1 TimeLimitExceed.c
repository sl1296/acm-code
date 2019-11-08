
#include <stdio.h>
int main(){
	int i,a,b,n,f[3];
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(!a && !b && !n)break;
		f[1]=f[2]=1;
		for(i=3;i<=n;i++)f[i%3]=(a*f[(i-1)%3]+b*f[(i-2)%3])%7;
		printf("%d\n",f[n%3]);
	}
	return 0;
}

