
#include <stdio.h>
int main(){
	int step,mod,i,l,j=0;
	while(scanf("%d%d",&step,&mod)!=EOF){
		if(!j)printf("%d%10d    ",step,mod);
		if(j)printf("%10d%10d    ",step,mod);
		l=step%mod;
		for(i=1;l;i++)l=(l+step)%mod;
		if(i==mod)printf("Good Choice"); else printf("Bad Choice");
		printf("\n\n");
		j++;
	}
	return 0;
}

