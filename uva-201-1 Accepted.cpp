
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
bool is[3][13][13];
int cc[15];
int main(){
	int n,m,cas=0;
	while(scanf("%d%d",&n,&m)!=EOF){
		char s[5];
		int ree=0;
		memset(is,false,sizeof(is));
		memset(cc,0,sizeof(cc));
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%s%d%d",s,&a,&b);
			if(s[0]=='H'){
				is[0][a][b]=true;
			}else{
				is[1][b][a]=true;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i;j++){
				for(int k=1;k<=n-i;k++){
					int z;
					for(z=0;z<i;z++){
						if(is[0][j][k+z]==false || is[0][j+i][k+z]==false || is[1][j+z][k]==false || is[1][j+z][k+i]==false)break;
					}
					if(z>=i)cc[i]++,ree++;
				}
			}
		}
		if(cas)printf("\n**********************************\n\n");
		cas++;
		printf("Problem #%d\n\n",cas);
		if(ree){
			for(int q=1;q<=n;q++){
				if(cc[q])printf("%d square (s) of size %d\n",cc[q],q);
			}
		}else{
			printf("No completed squares can be found.\n");
		}
	}
	return 0;
}

