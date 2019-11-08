
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int z[25][25],re;
int xx[5]={-1,0,0,1};
int yy[5]={0,-1,1,0};
typedef struct abc{
	char x[9],y[9];
	int step;
	struct abc *p;
}abc;
abc *start,*end,*ls;
int count;
int main(){
	int m,n,l,i,j,k,x,y;
	while(1){
		count++;
		scanf("%d%d%d",&m,&n,&l);
		if(!m && !n && !l)break;
		memset(z,0,sizeof(z));
		for(i=0;i<m+2;i++)z[i][0]=z[i][n+1]=1;
		for(i=1;i<=n;i++)z[0][i]=z[m+1][i]=1;
		start=(abc*)malloc(sizeof(abc));
		for(i=0;i<l;i++)scanf("%d%d",&start->x[i],&start->y[i]);
		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			z[x][y]=1;
		}
		start->step=0;
		end=start;
		while(1){
			for(i=0;i<4;i++){
				if(!z[start->x[0]+xx[i]][start->y[0]+yy[i]]){
					for(j=1;j<l;j++)if(start->x[0]+xx[i]==start->x[j] && start->y[0]+yy[i]==start->y[j])break;
					if(j<l)continue;
					if(start->x[0]+xx[i]==1 && start->y[0]+yy[i]==1){
						re=start->step+1;
						goto a;
					}
					end->p=(abc*)malloc(sizeof(abc));
					end=end->p;
					end->x[0]=start->x[0]+xx[i];
					end->y[0]=start->y[0]+yy[i];
					for(j=1;j<l;j++){
						end->x[j]=start->x[j-1];
						end->y[j]=start->y[j-1];
					}
					end->step=start->step+1;
			//		printf("%d %d %d\n",end->x[0],end->y[0],end->step);
			//		getchar();
				}
			}
			if(start==end){
				re=-1;
				break;
			}else{
				ls=start;
				start=start->p;
				free(ls);
			}
		}
		a:
		while(start!=end){
			ls=start;
			start=start->p;
			free(ls);
		}
		free(start);
		printf("Case %d: %d\n",count,re);
	}
	return 0;
}

