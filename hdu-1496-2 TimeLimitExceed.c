
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int a,b,c,d,i,j,l1,l2,e,count,t1,t2;
	int x[10100],y[10100];
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		count=0;
		e=0;
		for(i=1;i<101;i++){
			l1=a*i*i;
			l2=c*i*i;
			for(j=1;j<101;j++){
				x[e]=b*j*j+l1;
				y[e]=-d*j*j-l2;
			//	printf("%d %d:",x[e],y[e]);
			//	
				e++;
			}
		}
		qsort(x,10000,sizeof(int),*cmp);
		qsort(y,10000,sizeof(int),*cmp);
		j=0;
	//	for(i=9990;i<10000;i++){printf("%d %d:",x[i],y[i]);getchar();}
		for(i=0;i<10000;i++){
			while(x[i]>y[j] && j<10000)j++;
			if(j>9999)break;
			if(x[i]==y[j]){
				t1=t2=1;
				while(x[i+1]==x[i]){
					i++;
					t1++;
				}
				while(y[j+1]==y[j] && j<9999){
					j++;
					t2++;
				}
				count=count+t1*t2;
				j++;
				if(j>9999)break;
			}
		}
		count*=16;
		printf("%d\n",count);
	}
	return 0;
}

