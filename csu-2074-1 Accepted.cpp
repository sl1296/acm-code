
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s1[50]="aiyeou";
char s2[50]="AIYEOU";
char s3[50]="bkxznhdcwgpvjqtsrlmf";
char s4[50]="BKXZNHDCWGPVJQTSRLMF";
int x[300],y[300];
char in[1010];
int main(){
	for(int i=0;i<6;i++){
		x[s1[i]]=1;y[s1[i]]=i;
		x[s2[i]]=2;y[s2[i]]=i;
	}
	for(int i=0;i<20;i++){
		x[s3[i]]=3;y[s3[i]]=i;
		x[s4[i]]=4;y[s4[i]]=i;
	}
	while(gets(in)!=NULL){
		int len=strlen(in);
		for(int i=0;i<len;i++){
			switch(x[in[i]]){
				case 1:in[i]=s1[(y[in[i]]+3)%6];break;
				case 2:in[i]=s2[(y[in[i]]+3)%6];break;
				case 3:in[i]=s3[(y[in[i]]+10)%20];break;
				case 4:in[i]=s4[(y[in[i]]+10)%20];break;
			}
		}
		printf("%s\n",in);
	}
	return 0;
}

