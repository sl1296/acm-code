
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int t,i,l,p,z,j;
	char s[100],e[100];
	scanf("%d",&t);
	for(j=0;j<t;j++){
		scanf("%s",s);
		l=strlen(s);
		p=l;

		while(s[p-1]=='0' && p>0){p--;e[p]='0';
		}
		z=0;
		if(s[0]=='-'){z=1;e[0]='-';}
		for(i=p;i<l;i++){e[p]='0';}
		if(!z){for(i=0;i<p;i++)e[i]=s[p-i-1];}else{for(i=1;i<p;i++)e[i]=s[p-i];}
		e[l]=0;
		printf("%s\n",e);
	}
	return 0;
}

