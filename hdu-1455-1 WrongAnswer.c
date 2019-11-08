
#include <stdio.h>
#include <stdlib.h>
int n,a[70],sum,tryi[70],c,z[70],y[70],x,ise,isf;
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
void f(int len,int l,int w,int t){
	int i=w,j;
//	printf("%d %d %d %d\n",t,len,l,w);
//	for(j=0;j<x;j++)printf("%d-%d ",z[j],y[j]);
	//printf("\n");
	if(len==l){
		if(ise){
			i=0;
			while(!y[i])i++;
			y[i]--;
			ise--;
			f(len,z[i],i,t+1);
			y[i]++;
			ise++;
		}else{
			isf=1;
		}
	}else{
		for(;i<x;i++){
			if(y[i] && l+z[i]<=len){
				y[i]--;
				ise--;
				f(len,l+z[i],i,t+1);
				ise++;
				y[i]++;
				if(isf)break;
			}
		}
	}
}
int main(){
	int i;
	while(1){
		scanf("%d",&n);
		if(!n)break;
		sum=c=x=0;
		ise=n-1;
		isf=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		qsort(a,n,sizeof(int),*cmp);
		for(i=0;i<n;i++){
			y[x]=1;
			while(a[i]==a[i+1]){i++;y[x]++;}
			z[x]=a[i];
			x++;
		}
		for(i=a[0];i<=sum/2;i++)if(sum%i==0){tryi[c]=i;c++;}
		for(i=0;i<c;i++){
			y[0]--;
			f(tryi[i],a[0],0,1);
			y[0]++;
			if(isf)break;
		}
		printf("%d\n",tryi[i]);
	}
	return 0;
}

