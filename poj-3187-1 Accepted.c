
#include <stdio.h>
int n,sum,s,isf;
int re[12],p[12],ca[12];
void f(int z){
	int i;
	if(z==n){
		s=n;
		for(i=0;i<n;i++)ca[i]=re[i];
		while(s>1){for(i=0;i<s-1;i++)ca[i]+=ca[i+1];s--;}
		if(ca[0]==sum){
			for(i=0;i<n-1;i++)printf("%d ",re[i]);
			printf("%d\n",re[n-1]);
			isf=1;
		}
	}else{
		for(i=1;i<=n;i++){
			if(!p[i]){
				p[i]=1;
				re[z]=i;
				f(z+1);
				if(isf)break;
				p[i]=0;
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&sum);
	f(0);
	return 0;
}

