
#include<cstdio>
int main(){
	int t,sx[100];
	char s[100],ss[100],r[100];
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int n=0;
		for(int i=0;s[i];++i){
			if(s[i]>='A' && s[i]<='Z'){
				sx[n]=i;
				ss[n++]=s[i];
			}
		}
		if(n==2 && sx[0]==0 && sx[1]!=1 && ss[0]=='R' && ss[1]=='C'){
			int ta=0,tb=0;
			for(int i=1;i<sx[1];++i){
				ta=ta*10+s[i]-48;
			}
			for(int i=sx[1]+1;s[i];++i){
				tb=tb*10+s[i]-48;
			}
			--tb;
			if(tb<26){
				printf("%c",tb+'A');
			}else if(tb<26+26*26){
				tb-=26;
				printf("%c%c",tb/26+'A',tb%26+'A');
			}else if(tb<26+26*26+26*26*26){
				tb-=26+26*26;
				printf("%c%c%c",tb/26/26+'A',tb/26%26+'A',tb%26+'A');
			}else if(tb<26+26*26+26*26*26+26*26*26*26){
				tb-=26+26*26+26*26*26;
				printf("%c%c%c%c",tb/26/26/26+'A',tb/26/26%26+'A',tb/26%26+'A',tb%26+'A');
			}else{
				tb-=26+26*26+26*26*26+26*26*26*26;
				printf("%c%c%c%c%c",tb/26/26/26/26+'A',tb/26/26/26%26+'A',tb/26/26%26+'A',tb/26%26+'A',tb%26+'A');
			}
			printf("%d\n",ta);
		}else{
			int ta=0;
			if(n>1)ta+=26;
			if(n>2)ta+=26*26;
			if(n>3)ta+=26*26*26;
			if(n>4)ta+=26*26*26*26;
			int tmp=0;
			for(int i=0;i<n;++i){
				tmp=tmp*26+s[i]-'A';
			}
			++tmp;
			printf("R%sC%d\n",&s[n],ta+tmp);
		}
	}
	return 0;
}

