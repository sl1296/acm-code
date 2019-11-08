
#include <stdio.h>
int cnt;
void dfs(int *a,int k,int n,int c,int l,int r){
	int i,mask,t;
	if(k==n){
		cnt++;
	/*	if(cnt < 10) {
			for(i=0;i<n;i++) printf("%d ",a[i]);
			printf("\n");
		}*/
	}
	else{
		mask = c | l | r;
		for(i=0;i<n;i++){
			t = 1<<i;
			if(~mask&t){
				a[k] = i;				
				dfs(a,k+1,n,c|t,(l|t)<<1,(r|t)>>1);
			}
		}
	}	
}

int main(){
	int a[13],i,b[13];
	for(i=1;i<11;i++){cnt=0;dfs(a,0,i,0,0,0);b[i]=cnt;/*printf("%d\n",cnt);*/}
	while(1){
		scanf("%d",&i);
		if(!i)break;
		printf("%d\n",b[i]);
	}
	return 0;
}

