
#include <stdio.h>
int main(){
	int a,b,n,t[100000],i,j,s;
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(!a && !b && !n)break;
		t[1]=t[2]=1;
		for(i=3;;i++){
			t[i]=(a*t[i-1]+b*t[i-2])%7;
			for(j=2;j<i-1;j++)
				if(t[i]==t[j] && t[i-1]==t[j-1])goto a;
		}
		a:
		s=j-2;
		i=i-j;
		n=(n-s)%i;
		t[0]=t[i];
		printf("%d\n",t[s+n]);
	}
	return 0;
}

