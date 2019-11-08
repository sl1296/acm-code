
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[110][500];
int c[500];
int lc;
int l[110];
int main(){
	int i,j,k,m,n;
	a[0][0]=a[1][0]=1;
	a[2][0]=2;
	a[3][0]=5;
	l[0]=l[1]=l[2]=l[3]=1;
	for(i=4;i<102;i++){
		for(j=0;j<i;j++){
			lc=0;
			memset(c,0,sizeof(c));
			for(k=0;k<l[j];k++){
				for(m=0;m<l[i-j-1];m++){
					c[m+k]+=a[j][k]*a[i-j-1][m];
			//		printf("%d %d %d**",m,k,c[m+k]);
				}
			}
			//	for(m=0;m<5;m++)printf("%d ",c[m]);getchar();
			for(k=0;k<l[j]+l[i-j-1]-1;k++){
				if(c[k]>9){
					c[k+1]+=c[k]/10;
					c[k]%=10;
				}
			}
		//		for(m=0;m<5;m++)printf("%d ",c[m]);getchar();
		//	printf("*%d %d\n",c[k],k);
			if(!c[k]){lc=l[j]+l[i-j-1]-1;}else{
				while(c[k]>9){
					c[k+1]+=c[k]/10;
					c[k]%=10;
					k++;
				}
				lc=k+1;
			}

		//			for(m=0;m<5;m++)printf("%d ",c[m]);getchar();
			for(k=0;(k<lc || k<l[i]);k++){
				a[i][k]+=c[k];
				if(a[i][k]>9){
					a[i][k+1]+=a[i][k]/10;
					a[i][k]%=10;
				}
			}
	//		printf("%d ^%d %d\n",a[i][k-1],a[i][k],k);
			if(!a[i][k]){
				if(l[i]<lc)l[i]=lc;
			}else{
				while(a[i][k]>9){
					a[i][k+1]+=a[i][k]/10;
					a[i][k]%=10;
					k++;
		//			printf("%d ^%d %d\n",a[i][k-1],a[i][k],k);
				}
				l[i]=k+1;
			}
			
	//	for(k=l[i]-1;k>-1;k--)
	//	printf("%d",a[i][k]);
	//	printf(" \n%d\n",l[i]);
		}
	//	for(k=l[i]-1;k>-1;k--)
	//	printf("%d",a[i][k]);
	//	printf(" \n");getchar();
	}
	while(scanf("%d",&n)!=EOF){
		for(k=l[n]-1;k>-1;k--)
		printf("%d",a[n][k]);
		printf("\n");
	}
	return 0;
}

