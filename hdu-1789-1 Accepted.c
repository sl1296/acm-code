
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct zy{
	int t,v,n;
}zy;
zy x[1100];
zy list[1100];
int is[1100];
int l;
int cmp(const void *a,const void *b){
	zy *e=(zy*)a,*f=(zy*)b;
	return (e->t)-(f->t);
}
int cmp2(const void *a,const void *b){
	zy *e=(zy*)a,*f=(zy*)b;
	return (f->v)-(e->v);
}
int main(){
	int t,i,n,re,j,c,k;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		re=0;
		memset(is,0,sizeof(is));
		scanf("%d",&n);
		for(j=0;j<n;j++)scanf("%d",&x[j].t);
		for(j=0;j<n;j++)scanf("%d",&x[j].v);
		qsort(x,n,sizeof(zy),*cmp);
		l=0;
		for(j=0;j<n;j++){
			c=j;
			while(x[j+1].t==x[j].t && j<n-1)j++;
			if(j-c+1+l>x[j].t){
				for(k=c;k<=j;k++){
					list[l+k-c].t=x[k].t;
					list[l+k-c].v=x[k].v;
					list[l+k-c].n=k;
				}
				l=l+j-c+1;
				qsort(list,l,sizeof(zy),*cmp2);
				l=x[j].t;
			}else{
				for(k=c;k<=j;k++){
					list[l+k-c].t=x[k].t;
					list[l+k-c].v=x[k].v;
					list[l+k-c].n=k;
				}
				l=l+j-c+1;
			}
		}
		for(j=0;j<l;j++)is[list[j].n]=1;
		for(j=0;j<n;j++)if(!is[j])re+=x[j].v;
		printf("%d\n",re);
	}
	return 0;
}

