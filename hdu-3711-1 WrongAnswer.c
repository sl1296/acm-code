
#include <stdio.h>
int main(){
	int t,i,j,k,m,n,a[110],b,c,d,min,minl;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d%d",&m,&n);
		for(j=0;j<m;j++)scanf("%d",&a[j]);
		for(j=0;j<n;j++){
			min=100;
			scanf("%d",&b);
			for(k=0;k<m;k++){
				c=a[k]^b;
				d=0;
				while(c){
					d+=c%2;
					c/=2;
				}
				if(d<min){
					min=d;
					minl=a[k];
				}
			}
			printf("%d\n",minl);
		}
	}
	return 0;
}

