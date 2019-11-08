
#include <stdio.h>
int main(){
	int t,i,x,y,z,f[11][5]={{1,0},{1,1},{4,2,4,8,6},{4,3,9,7,1},{2,4,6},{1,5},{1,6},{4,7,9,3,1},{4,8,4,2,6},{2,9,1}};
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&x);
		y=x%10;
		z=x%f[y][0];
		if(!z)z=f[y][0];
		printf("%d\n",f[y][z]);
	}
	return 0;
}

