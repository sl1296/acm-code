
#include <stdio.h>
#include <string.h>
int main(){
	int i,j,n,c,x[1010],max,mn;
	char s[1010][20],l[20];
	while(1){
		c=0;
		scanf("%d",&n);
		if(!n)break;
		for(i=0;i<n;i++){
			scanf("%s",l);
			for(j=0;j<c;j++)if(!strcmp(l,s[j]))break;
			if(j<c){
				x[j]++;
			}else{
				strcpy(s[c],l);
				x[c]=1;
				c++;
			}
		}
		max=0;
		for(i=0;i<c;i++){
			if(x[i]>max){
				max=x[i];
				mn=i;
			}
		}
		printf("%s\n",s[mn]);
	}
	return 0;
}

