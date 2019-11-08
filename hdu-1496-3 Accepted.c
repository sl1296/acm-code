
#include <stdio.h>
#include <string.h>
int z[2001000];
int main(){
	int a,b,c,d,i,j,l1,count;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		count=0;
		memset(z,0,sizeof(z));
		for(i=1;i<101;i++){
			l1=a*i*i;
			for(j=1;j<101;j++){
				z[b*j*j+l1+1000500]++;
			}
		}
		for(i=1;i<101;i++){
			l1=c*i*i;
			for(j=1;j<101;j++){
				count=count+z[-l1-d*j*j+1000500]*16;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}

