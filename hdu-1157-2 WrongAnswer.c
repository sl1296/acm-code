
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b);
int main(){
	int n,i,a[10010];
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),*cmp);
	printf("%d",a[(n-1)/2]);
	return 0;
}
int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

