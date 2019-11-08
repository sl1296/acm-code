
#include <stdio.h>
int main(){
	int i,a,b,n,f[100000],pd,k;
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(!a && !b && !n)break;
		pd=0;
		f[1]=f[2]=1;
		for(i=3;i<=n;i++){f[i]=(a*f[i-1]+b*f[i-2])%7;if(f[i]==1 && f[i-1]==1){pd=1;break;}}
		if(pd){
			k=n%(i-2);
			if(!k)k=i-2;
			printf("%d\n",f[k]);
		}else{
			printf("%d\n",f[n]);}
	}
	return 0;
}

