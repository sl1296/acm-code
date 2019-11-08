
#include <stdio.h>
#include <stdlib.h>
int z[3100];
int xn[9100];
int main(){
	int  n,i,y=0,j,c=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&z[i]);
		xn[z[i]]++;
	}
/*	for(i=0;i<3010;i++){
		while(z[i+1]==z[i]){
			i++;
			xn[y]++;
		}
		xn[y]++;
		x[y]=a[i];
		y++;
	}*/
	for(i=0;i<3001;i++){
		if(xn[i]>1){
			for(j=i+1;xn[i]>1;j++){
				if(!xn[j]){
					xn[j]++;
					xn[i]--;
					c=c+j-i;
				}
			}
		}
	}
	printf("%d\n",c);
	return 0;
}

