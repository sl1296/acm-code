
#include <stdio.h>
int n,a[10][10],min,b[10];
void cc(int y,int i){
	int k;
	for(k=n-i;k<n;k++)b[k-n+i]=a[y][k];
	for(k=n-i-1;k>-1;k--)a[y][k+i]=a[y][k];
	for(k=0;k<i;k++)a[y][k]=b[k];
}
void f(int y){
	int i,j,max=0,sum;
	if(y==n){
		for(j=0;j<n;j++){
			sum=0;
			for(i=0;i<n;i++)sum+=a[i][j];
			if(sum>max)max=sum;
		}
		if(max<min)min=max;
	}else{
		f(y+1);
		for(i=1;i<n;i++){
			cc(y,i);
			f(y+1);
			cc(y,n-i);
		}
	}
}
int main(){
	int i,j;
	while(1){
		min=9999999;
		scanf("%d",&n);
		if(n==-1)break;
		for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
		f(0);
		printf("%d\n",min);
	}
	return 0;
}

