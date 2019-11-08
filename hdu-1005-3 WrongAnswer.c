
#include <stdio.h>
int main(){
	int i,a,b,n,f[100000],pd,k,pd2,j;
	while(1){
		scanf("%d%d%d",&a,&b,&n);
		if(!a && !b && !n)break;
		pd=0;
		f[1]=f[2]=1;
		for(i=3;i<=n;i++){f[i]=(a*f[i-1]+b*f[i-2])%7;
		pd2=0;
		for(j=1;j<i-1;j++)
			if(f[i]==f[j+1] && f[i-1]==f[j]){pd2=1;break;}
			if(pd2)
			{pd=1;break;}
		
		}

		if(pd){
			k=(n-j+1)%(i-2);
			if(!k)k=i-2;
			k+=j-1;
			printf("%d\n",f[k]);
		}else{
			printf("%d\n",f[n]);}
	}
	return 0;
}

