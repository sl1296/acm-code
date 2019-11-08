
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[100][100];
int re,m,n;
int b[100][100];
int is[100][100];
int x[15][4]={{1,0,0,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},{1,0,1,0},{0,1,0,1},{1,1,0,1},{1,0,1,1},{0,1,1,1},{1,1,1,0},{1,1,1,1}};
void find(int i,int j){
//	printf("%d %d:",i,j);
	is[i][j]=1;
	if(i>0 && x[b[i][j]][0]==1 && x[b[i-1][j]][2]==1 && !is[i-1][j])find(i-1,j);
	if(j>0 && x[b[i][j]][3]==1 && x[b[i][j-1]][1]==1 && !is[i][j-1])find(i,j-1);
	if(i<m-1 && x[b[i][j]][2]==1 && x[b[i+1][j]][0]==1 && !is[i+1][j])find(i+1,j);
	if(j<n-1 && x[b[i][j]][1]==1 && x[b[i][j+1]][3]==1 && !is[i][j+1])find(i,j+1);
}
int main(){
	int i,j;
	while(1){
		scanf("%d%d",&m,&n);
		if(m==-1 && n==-1)break;
		re=0;
		memset(is,0,sizeof(is));
		for(i=0;i<m;i++){
			scanf("%s",&a[i]);
			for(j=0;j<n;j++)b[i][j]=a[i][j]-65;
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(!is[i][j]){find(i,j);re++;}
			}
		}
		printf("%d\n",re);
	}
	return 0;
}

