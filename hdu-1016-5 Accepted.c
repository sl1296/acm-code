
#include <stdio.h>
int p[23],c;
void f(int *a,int n,int z){
	int i;
	if(z==n){
		if(a[z-1]==2 || a[z-1]==4 || a[z-1]==6 || a[z-1]==10 || a[z-1]==12 || a[z-1]==16 || a[z-1]==18 || a[z-1]==22 || a[z-1]==28 || a[z-1]==30 || a[z-1]==36)
		{	for(i=0;i<n;i++){printf("%d",a[i]);if(i<n-1)printf(" ");}printf("\n");c++;}
	}else{
		for(i=2;i<=n;i++)if(!p[i] && (i+a[z-1]==3 || i+a[z-1]==5 || i+a[z-1]==7 || i+a[z-1]==11 || i+a[z-1]==13 || i+a[z-1]==17 || i+a[z-1]==19 || i+a[z-1]==23 || i+a[z-1]==29 || i+a[z-1]==31 || i+a[z-1]==37))
		{p[i]=1;a[z]=i;f(a,n,z+1);p[i]=0;}
	}
}
int main(){
	int n,a[23]={1},i=0;
	while(scanf("%d",&n)!=EOF){
		i++;
		c=0;
		printf("Case %d:\n",i);
		f(a,n,1);
	//	if(!c)printf("\n");
		printf("\n");
	}
	return 0;
}

