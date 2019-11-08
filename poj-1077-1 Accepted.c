
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int is[362890],count;
char re[1000];
typedef struct abc{
	char a[9];
	int step;
	int x;
	char t;
	struct abc *p,*pre;
}abc;
abc *start,*end,*ls;
char cvs[5]="lrud";
int fac[8]={1,2,6,24,120,720,5040,40320};
int cv[9][4]={-1, 1,-1, 3,
	           0, 2,-1, 4,
	           1,-1,-1, 5,
	          -1, 4, 0, 6,
	           3, 5, 1, 7,
	           4,-1, 2, 8,
	          -1, 7, 3,-1,
	           6, 8, 4,-1,
	           7,-1, 5,-1};
int hash(char *a){
	int i,j,s=0,c;
	for(i=0;i<8;i++){
		for(c=0,j=i+1;j<9;j++) if(a[i]>a[j]) c++;
		s += c*fac[7-i];
	}
	return s;
}
int main(){
	int i,j,h;
	char l[2];
	start=(abc*)malloc(sizeof(abc));
	for(i=0;i<9;i++){
		scanf("%s",l);
		if(l[0]=='x'){
			start->a[i]=9;
			start->x=i;
		}else{
			start->a[i]=l[0]-48;
		}
	}
	start->step=0;
	end=start;
	h=hash(start->a);
	is[h]=1;
	while(1){
		for(i=0;i<4;i++){
			if(cv[start->x][i]!=-1){
				start->a[start->x]=start->a[cv[start->x][i]];
				start->a[cv[start->x][i]]=9;
				h=hash(start->a);
				if(!is[h]){
					end->p=(abc*)malloc(sizeof(abc));
					end=end->p;
					for(j=0;j<9;j++)end->a[j]=start->a[j];
					end->step=start->step+1;
					end->x=cv[start->x][i];
					end->t=cvs[i];
					end->pre=start;
					is[h]=1;
					if(!h)goto a;
					count++;
				}
				start->a[cv[start->x][i]]=start->a[start->x];
				start->a[start->x]=9;
			}
		}
		start=start->p;
		if(count>362878){
			printf("unsolvable\n");
			return 0;
		}
	}
	a:
	re[end->step]=0;
	for(i=end->step-1;i>-1;i--){
		re[i]=end->t;
		end=end->pre;
	}
	printf("%s\n",re);
	return 0;
}

