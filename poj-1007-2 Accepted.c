
#include <stdio.h>
#include <stdlib.h>
int z[110];
int cmp(const void *a,const void *b);
int main(){
	int n,m,i,j,k,y[110];
	char s[110][55];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%s",s[i]);
		for(j=0;j<n-1;j++)for(k=j+1;k<n;k++)if(s[i][j]>s[i][k])z[i]++;
		y[i]=i;
	}
	qsort(y,m,sizeof(int),*cmp);
	for(i=0;i<m;i++)printf("%s\n",s[y[i]]);
	return 0;
}
int cmp(const void *a,const void *b){
	int t;
	t=z[*(int*)a]-z[*(int*)b];
	if(t==0)t++;
	return t;
}

