
#include <stdio.h>
char z[25][25];
int sx,sy,count;
int xx[5]={-1,1,0,0};
int yy[5]={0,0,-1,1};
void find(int x,int y){
	int i;
//	printf("%d %d\n",x,y);
	count++;
	for(i=0;i<4;i++){
//		printf("--%d-%d-%c\n",x+xx[i],y+yy[i],z[x+xx[i]][y+yy[i]]);
		if(z[x+xx[i]][y+yy[i]]=='.'){
			z[x+xx[i]][y+yy[i]]=0;
			find(x+xx[i],y+yy[i]);
		}
	}
}
int main(){
	int x,y,i,j;
	while(1){
		scanf("%d%d",&y,&x);
		if(!x && !y)break;
		count=0;
		for(i=1;i<=x;i++){
			scanf("%s",&z[i][1]);
			for(j=1;j<=y;j++)if(z[i][j]=='@'){
				sx=i;
				sy=j;
			}
		//	printf("%s\n",&z[i][1]);
		}
		find(sx,sy);
		printf("%d\n",count);
	}
	return 0;
}


