
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
char s[55][1010];
map<char,int> ma;
int main(){
	char ch[5]="ACGT";
	int t;
	scanf("%d",&t);
	ma['A']=0;
	ma['C']=1;
	ma['G']=2;
	ma['T']=3;
	while(t--){
		int m,n;
		int cc[6];
		scanf("%d%d",&m,&n);
		for(int i=0;i<m;i++)scanf("%s",s[i]);
		int ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<4;j++)cc[j]=0;
			for(int j=0;j<m;j++){
				cc[ma[s[j][i]]]++;
			}
			int mmax=0;
			for(int j=1;j<4;j++)if(cc[j]>cc[mmax])mmax=j;
			printf("%c",ch[mmax]);
			ans=ans+m-cc[mmax];
		}
		printf("\n%d\n",ans);
	}
	return 0;
}

