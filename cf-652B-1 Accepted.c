
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,a[1100],i,j;
	while(scanf("%d",&n)!=EOF){
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),*cmp);
	i=0;j=n-1;
	while(i<j){
		printf("%d %d",a[i],a[j]);
		i++;j--;
		if(i<j)printf(" ");
	}
	if(i==j)printf(" %d",a[i]);
	printf("\n");
	}
	return 0;
}


