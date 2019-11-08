
#include <stdio.h>
#include <math.h>
#define INF 0x3f3f3f3f
int min = INF;
int n,m;
int mins[21],mind[21];
void init();
void dfs(int k,int r,int h,int s,int d);
int main(){
	int mr,mh,h,r;
	scanf("%d%d",&n,&m);
	init();
	mh=(n-mind[m-1])/(m*m);
	mr=sqrt((n-mind[m-1])/m);
	//for(h=m;h<=mh;h++)for(r=m;r<=mr;r++)
	dfs(0,mr,mh,0,0);
	printf("%d",min);
	return 0;
}
void init(){
	int i;
	mins[0] = 0;
	mind[0] = 0;
	for(i=1;i<=20;i++){
		mins[i] = mins[i-1]+2*i*i;
		mind[i] = mind[i-1]+i*i*i;
	} 
}

void dfs(int k,int r,int h,int s,int d){
	int i,j,ld;
	
	if(k==m){
		if(d==n && s < min) min = s;
		return;
	}
	
	ld = n - d;	
	for(i=r-1;i>m-k-1;i--){
		int maxh,ts=0,td;
		maxh = (ld-mind[m-k-1])/(i*i);
		if(maxh > h-1) maxh = h-1;
		for(j=maxh;j>m-k-1;j--){			
			td = ld - i*i*j;
			if(td < mind[m-k-1]) continue;
							
			if(k==0) ts = i*i + 2*i*j;
			else ts = s + 2*i*j;	
			if(ts+mins[m-k-1] >= min || ts + 2*td/i >= min) continue;					

			dfs(k+1,i,j,ts,d+i*i*j);			
		}
	}
}


