
#include <stdio.h>
int n,k,c,x[10],y[10];
char a[10][10];
void f(int z,int u,int v){
	int i,j;
//	printf("%d %d %d\n",z,u,v);
	if(z==k){
		c++;
	}else{
		for(i=u;i<n;i++){
			for(j=(i==u?v:0);j<n;j++){
				if(a[i][j]=='#' && x[i]==0 && y[j]==0){
					a[i][j]=0;
					x[i]=1;
					y[j]=1;
					f(z+1,i,j);
					x[i]=0;
					y[j]=0;
					a[i][j]='#';
				}
			}
		}
	}
}
int main(){
	int i;
	while(1){
		scanf("%d%d",&n,&k);
		if(n==-1 && k==-1)break;
		c=0;
		for(i=0;i<n;i++){
			scanf("%s",a[i]);
			x[i]=y[i]=0;
		}
		f(0,0,0);
		printf("%d\n",c);
	}
	return 0;
}

