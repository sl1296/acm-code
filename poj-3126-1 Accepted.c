
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int s[5],e[5],zs[10100],iszs[10100],zsn,isuse[10100],exit1,ans;
int xxxx[5]={1000,100,10,1};
typedef struct num{
	int num[5];
	int i;
	struct num *p;
}num;
num *x,*y,*ls;
int main(){
	int t,i,j,k,start,end,sum;
	scanf("%d",&t);
	zs[0]=2;zs[1]=3;zs[2]=5;zs[3]=7;zsn=4;
	iszs[2]=iszs[3]=iszs[5]=iszs[7]=1;
	for(i=11;i<10010;i++){
		for(j=0;j<zsn;j++)if(i%zs[j]==0)break;
		if(j==zsn){
			zs[zsn]=i;
			zsn++;
			iszs[i]=1;
	//		printf("%d;",zs[zsn-1]);
		}
	}
	for(i=0;i<t;i++){
		memset(isuse,0,sizeof(isuse));
		exit1=1;
		scanf("%d%d",&start,&end);
		if(start==end){
			printf("0\n");
			continue;
		}
		isuse[start]=1;isuse[end]=2;
	//	printf("111111");
		x=(num*)malloc(sizeof(num));
		x->num[0]=start/1000;
		start%=1000;
		x->num[1]=start/100;
		start%=100;
		x->num[2]=start/10;
		start%=10;
		x->num[3]=start;
		x->i=0;
		y=x;
		e[0]=end/1000;
		end%=1000;
		e[1]=end/100;
		end%=100;
		e[2]=end/10;
		end%=10;
		e[3]=end;
		while(exit1){
			for(j=0;j<4;j++){
				for(k=(j?0:1);k<10;k++){
				//	printf("te:j=%d,k=%d,x->num[j]=%d?????\n",j,k,x->num[j]);
					if(x->num[j]==k)continue;
					sum=x->num[0]*1000+x->num[1]*100+x->num[2]*10+x->num[3]-x->num[j]*xxxx[j]+k*xxxx[j];
					if(iszs[sum] && isuse[sum]==0){
			//			printf("%d-%d-\n",sum,x->i);
						y->p=(num*)malloc(sizeof(num));
						y=y->p;
						y->i=x->i+1;
						y->num[0]=x->num[0];
						y->num[1]=x->num[1];
						y->num[2]=x->num[2];
						y->num[3]=x->num[3];
						y->num[j]=k;
						isuse[sum]=1;
					}else if(isuse[sum]==2){
						ans=x->i+1;
						exit1=0;
						break;
					}
				}
				if(!exit1)break;
			}
			ls=x;
			x=x->p;
			free(ls);
	//		getchar();
		}
		printf("%d\n",ans);
		while(x!=y){
			ls=x;
			x=x->p;
			free(ls);
		}
		free(x);
	}
	return 0;
}

