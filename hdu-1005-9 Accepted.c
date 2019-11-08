
#include <stdio.h>
int main(){
	int a,b,n,t[100000],i;
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(!a && !b && !n)break;
		t[1]=t[2]=1;
		for(i=3;i<100;i++){
			t[i]=(a*t[i-1]+b*t[i-2])%7;
			if(t[i]==1 && t[i-1]==1)break;
		}
		i-=2;
		n%=i;
		t[0]=t[i];
		printf("%d\n",t[n]);
	}
	return 0;
}

