
#include <stdio.h>
#include <math.h>
int z[665000];
int main(){
	int n,i,j,x,t,xc=4,xt,xi,xj,xp,len=7;
	scanf("%d",&n);
	z[0]=2;z[1]=3;z[2]=5;z[3]=7;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		if(x>len){
	for(xi=len+1;xi<=x;xi++){
		xp=1;
		xt=sqrt(xi);
		for(xj=0;z[xj]<=xt;xj++)if(xi%z[xj]==0){xp=0;break;}
		if(xp){z[xc]=xi;xc++;}
	}
		z[xc]=x+1;
		len=x;
		}
		for(j=0;z[j]<=x;j++);
		printf("%d\n",z[j-1]);
	}
	return 0;
}

