
#include <stdio.h>
char map[5][5];
int n,max;
void f(int c){
	int i,j,k,fi=0,pd;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(map[i][j]=='.'){
				pd=1;
				for(k=i;map[k][j]!='X' && k>-1;k--)if(!map[k][j])pd=0;
				for(k=i;map[k][j]!='X' && k<n;k++)if(!map[k][j])pd=0;
				for(k=j;map[i][k]!='X' && k>-1;k--)if(!map[i][k])pd=0;
				for(k=j;map[i][k]!='X' && k<n;k++)if(!map[i][k])pd=0;
				if(pd){
					map[i][j]=0;
					f(c+1);
					map[i][j]='.';
					fi=1;
				}
			}
		}
	}
	if(!fi)if(c>max)max=c;
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(!n)break;
		max=0;
		for(i=0;i<n;i++)scanf("%s",map[i]);
		f(0);
		printf("%d\n",max);
	}
	return 0;
}

