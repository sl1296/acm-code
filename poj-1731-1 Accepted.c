
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[210],z[210],re[210];
int len,nn,n[210];
int cmp(const void *a,const void *b){
	return *(char*)a-*(char*)b;
}
void f(int y){
	int i;
//	printf("%d\n",y);
	if(y==len){
		printf("%s\n",re);
	}else{
		for(i=0;i<nn;i++){
			if(n[i]){
				n[i]--;
				re[y]=z[i];
				f(y+1);
				n[i]++;
			}
		}
	}
}
int main(){
	int i;
	scanf("%s",s);
	len=strlen(s);
//	printf("%d\n",len);
	re[len]=0;
	qsort(s,len,sizeof(char),*cmp);
	for(i=0;i<len;i++){
		while(s[i+1]==s[i]){i++;n[nn]++;}
		n[nn]++;
		z[nn]=s[i];
		nn++;
	}
	f(0);
	return 0;
}

