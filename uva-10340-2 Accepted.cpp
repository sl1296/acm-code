
#include<cstdio>
#include<cstdlib>
#include<cstring>
char a[100000],b[100000];
int main(){
	while(scanf("%s%s",a,b)!=EOF){
		int la=strlen(a);
		int lb=strlen(b);
		int p=0;
		int i;
		for(i=0;i<la;i++){
			while(b[p]!=a[i] && p<lb)p++;
			if(b[p]==a[i]){
				p++;
			}else{
				break;
			}
		}
		if(i<la)printf("No\n");else printf("Yes\n");
	}
	return 0;
}

