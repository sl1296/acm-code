
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int z[25][25],re;
int xx[5]={-1,0,0,1};
int yy[5]={0,-1,1,0};
int hh[7]={1024,256,64,16,4,1};
char is[6553610];
typedef struct abc{
	char n[9],x,y;
	int step;
	struct abc *p;
}abc;
abc *start,*end,*ls;
int count;
int main(){
	int m,n,l,i,j,k,x,y,x2,y2,h,l2;
	while(1){
		count++;
		scanf("%d%d%d",&m,&n,&l);
		if(!m && !n && !l)break;
		memset(z,0,sizeof(z));
		memset(is,0,sizeof(is));
		for(i=0;i<m+2;i++)z[i][0]=z[i][n+1]=1;
		for(i=0;i<n+2;i++)z[0][i]=z[m+1][i]=1;
		start=(abc*)malloc(sizeof(abc));+
		scanf("%d%d",&start->x,&start->y);
		x2=start->x;
		y2=start->y;
		h=(x2*20-21+y2)*16384;
		l--;
		for(i=0;i<l;i++){
			scanf("%d%d",&x,&y);
			for(j=0;j<4;j++){
				if(x2+xx[j]==x && y2+yy[j]==y){
					start->n[i]=j;
					if(i>0)h+=j*hh[i-1]; else h+=j*4096;
			//		printf("%d:%d\n",i,j);
					break;
				}
			}
			x2=x;
			y2=y;
		}
		is[h]=1;
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
		end=start;
		l2=l-1;
		
	/*				printf("%d %d %d\n",end->x,end->y,end->step);
					for(j=0;j<l;j++)printf("%d ",end->n[j]);
					printf("\n");
					getchar();*/
		while(1){
			for(i=0;i<4;i++){
				if(!z[start->x+xx[i]][start->y+yy[i]]){
					x2=start->x;
					y2=start->y;
					x=x2+xx[i];
					y=y2+yy[i];
					for(j=0;j<l;j++){
						x2+=xx[start->n[j]];
						y2+=yy[start->n[j]];
			//			printf("%d:%d,%d-%d,%d\n",j,x,y,x2,y2);
						if(x2==x && y2==y)break;
					}
					if(j<l)continue;
					h=(x*20+y-21)*16384+i*4096;
					for(j=0;j<l2;j++)h+=start->n[j]*hh[j];
					if(is[h])continue;
					is[h]=1;
					if(x==1 && y==1){
						re=start->step+1;
						goto a;
					}
					end->p=(abc*)malloc(sizeof(abc));
					end=end->p;
					end->x=x;
					end->y=y;
					end->n[0]=3-i;
					for(j=1;j<l;j++)end->n[j]=start->n[j-1];
					end->step=start->step+1;
			//		printf("%d %d %d\n",end->x,end->y,end->step);
			/*		for(j=0;j<l;j++)printf("%d ",end->n[j]);
					printf("\n");*/
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

