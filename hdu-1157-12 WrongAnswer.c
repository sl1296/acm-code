
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int main(){
	int n,i,a[10010],t;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),*cmp);
	t=n/2;
	printf("%d\n",a[t]);
	return 0;
}

