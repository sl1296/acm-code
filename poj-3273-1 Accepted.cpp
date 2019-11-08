
#include <stdio.h>
#define N 100000
#define FU(i,n) for(i=0;i<(n);i++)
int c[N];

int main(){
	int n,m,i,t,k,L,R,mid;
	scanf("%d %d",&n,&m);
	L=-1,R=0;
	FU(i,n){
		scanf("%d",c+i);
		R += c[i];
		if(c[i]>L) L = c[i];
	}

	while(R>L){
		mid = (R+L)>>1;
		t = 0,k = 0;
		FU(i,n){
			if(k+c[i]<=mid) k+=c[i];
			else t++,k=c[i];
		}
		if(t+1 > m) L = mid+1;
		else R = mid-1;
	}
	printf("%d\n",L);

	return 0;
}

