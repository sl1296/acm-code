
#include <stdio.h>
int main(){
	int i,tt,j,k,c,m,z;
	char s[10010],t[10010],l[10];
	scanf("%d",&tt);
	for(i=0;i<tt;i++){
		scanf("%s",s);
		k=0;
		for(j=0;s[j];j++){
			c=0;
			while(s[j+1]==s[j]){j++;c++;}
			if(c){
				c++;
				m=0;
				while(c>9){
					l[m]=c%10;
					m++;
					c/=10;
				}
				l[m]=c;
				for(;m>-1;m--){t[k]=l[m]+48;k++;}
				t[k]=s[j];
				k++;
			}else{
				t[k]=s[j];
				k++;
			}
		}
		t[k]=0;
		printf("%s\n",t);
	}
	return 0;
}

