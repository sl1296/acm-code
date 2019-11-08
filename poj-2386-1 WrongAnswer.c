
#include <stdio.h>
char a[110][110];
int isa[110][110];
int xx[10]={-1,-1,-1,0,1,1,1,0};
int yy[10]={-1,0,1,1,1,0,-1,-1};
void find(int x,int y);
int main(){
	int m,n,i,j,c=0;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)scanf("%s",&a[i][1]);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(!isa[i][j] && a[i][j]=='W'){
				find(i,j);
			//	printf("%d %d:",i,j);
				c++;
			}
		}
	}
	printf("%d\n",c);
	return 0;
}
void find(int x,int y){
	int i;
	isa[x][y]=1;
//	printf("%d%d\\\\",x,y);
	for(i=0;i<8;i++)if(a[x+xx[i]][y+yy[i]]=='W' && isa[x+xx[i]][y+yy[i]]==0)find(x+xx[i],y+yy[i]);
}

