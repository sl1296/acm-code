
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[15],re[7];
int n,p[15],isf,len;
int cmp(const void *a,const void *b);
void f(int z){
	int i;
	if(z==5){
		if(re[0]-re[1]*re[1]+re[2]*re[2]*re[2]-re[3]*re[3]*re[3]*re[3]+re[4]*re[4]*re[4]*re[4]*re[4]==n){
			printf("%c%c%c%c%c\n",re[0]+64,re[1]+64,re[2]+64,re[3]+64,re[4]+64);
			isf=1;
		}
	}else{
		for(i=0;i<len;i++){
			if(!p[i]){
				p[i]=1;
				re[z]=s[i]-64;
				f(z+1);
				p[i]=0;
				if(isf)break;
			}
		}
	}
}
int main(){
	while(1){
		scanf("%d%s",&n,s);
		if(!strcmp(s,"END") && !n)break;
		isf=0;
		len=strlen(s);
		qsort(s,len,sizeof(char),*cmp);
		f(0);
		if(!isf)printf("no solution\n");
	}
	return 0;
}
int cmp(const void *a,const void *b){
	return *(char*)b-*(char*)a;
}

