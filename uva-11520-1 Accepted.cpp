
#include<cstdio>
#include<cstring>
using namespace std;
char a[14][14];
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		int n;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)scanf("%s",&a[i][1]);
		int xx[5]={0,0,1,-1};
		int yy[5]={1,-1,0,0};
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		if(a[i][j]=='.'){
			a[i][j]='A';
			while(1){
			int k;
			for(k=0;k<4;k++){
				int tx=i+xx[k];
				int ty=j+yy[k];
				if(a[tx][ty] &&a[tx][ty]==a[i][j])break;
			}
			if(k<4)a[i][j]++;else break;
			}
		}
		printf("Case %d:\n",z);
		for(int i=1;i<=n;i++)printf("%s\n",&a[i][1]);
	}
	return 0;
}

