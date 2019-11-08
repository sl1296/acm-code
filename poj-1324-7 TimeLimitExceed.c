
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int z[25][25],re;
int xx[5]={-1,0,0,1};
int yy[5]={0,-1,1,0};
int hh[7]={1,4,16,64,256,1024,4096};
char is[6553610];
int nn[9];
typedef struct abc{
	char x[8],y[8];
	int h;
	int step;
	struct abc *p;
}abc;
abc *start,*end,*ls;
int count;
int main(){
	int m,n,l,i,j,k,x,y,x2,y2,h;
	while(1){
		count++;
		scanf("%d%d%d",&m,&n,&l);
		if(!m && !n && !l)break;
		memset(z,0,sizeof(z));
		memset(is,0,sizeof(is));
		for(i=0;i<m+2;i++)z[i][0]=z[i][n+1]=1;
		for(i=0;i<n+2;i++)z[0][i]=z[m+1][i]=1;
		start=(abc*)malloc(sizeof(abc));
		end=start;
		scanf("%d%d",&x2,&y2);
		start->x[0]=x2;
		start->y[0]=y2;
		h=(x2*20-21+y2)*16384;
		for(i=1;i<l;i++){
			scanf("%d%d",&x,&y);
			start->x[i]=x;
			start->y[i]=y;
			for(j=0;j<4;j++){
				if(x2+xx[j]==x && y2+yy[j]==y){
					nn[i-1]=j;
					h+=j*hh[i];
		//			printf("%d:%d\n",i,j);
					break;
				}
			}
			x2=x;
			y2=y;
		}
		is[h]=1;

	/*	printf("%d %d\n",end->h,end->step);
		for(j=0;j<l;j++)printf("%d:%d ",end->x[j],end->y[j]);
		printf("\n");*/

		scanf("%d",&k);
		for(i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			z[x][y]=1;
		}
	/*	for(i=0;i<m+2;i++){
			for(j=0;j<n+2;j++){
				printf("%d ",z[i][j]);
			}
			printf("\n");
		}*/
		start->step=0;
		start->h=h;
		
			/*		printf("%d %d\n",end->h,end->step);
					for(j=0;j<l;j++)printf("%d:%d ",end->x[j],end->y[j]);
					printf("\n");*/
			//		getchar();
		while(1){
			for(i=0;i<4;i++){
				x=start->x[0]+xx[i];
				y=start->y[0]+yy[i];
				if(!z[x][y]){
					for(j=1;j<l;j++){
						if(x==start->x[j] && y==start->y[j])break;
					}
					if(j<l)continue;
					h=(x*20+y-21)*16384+i+(start->h%4096)*4;
					if(is[h])continue;
					is[h]=1;
					if(x==1 && y==1){
						re=start->step+1;
						goto a;
					}
					end->p=(abc*)malloc(sizeof(abc));
					end=end->p;
					end->x[0]=x;
					end->y[0]=y;
					for(j=1;j<l;j++){
						end->x[j]=start->x[j-1];
						end->y[j]=start->y[j-1];
					}
					end->h=h;
					end->step=start->step+1;
				
				/*	printf("%d %d\n",end->h,end->step);
					for(j=0;j<l;j++)printf("%d:%d ",end->x[j],end->y[j]);
					printf("\n");*/
				//	getchar();

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

