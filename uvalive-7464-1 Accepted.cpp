
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int ans;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		int x,y,m,n,xx,bl;
		scanf("%d%d%d%d",&x,&y,&m,&n);
		if(x>y){
			xx=x;x=y;y=xx;
			xx=m;m=n;n=xx;
		}
		bl=y/x;
		int zm=m,zn=n;
		while(m+n){
			int add=x;
			if(n>0){n--;add=y;}
			else m--;
			if(n>0){
				if(n>zm){
					m=zm;
					n-=zm;
					n=(n+1)/2;
				}else{
					int tmp=m-n;
					m=n;
					n=0;
					if(tmp>1){
						for(int i=0;i<bl;i++){
							tmp=(tmp+1)/2;
						}
					}else tmp=0;
					m+=tmp;
				}
			}else{
				if(add==x){
					m=(m+1)/2;
				}else{
					for(int i=0;i<bl;i++){
						m=(m+1)/2;
					}
				}
			}
			ans+=add;
		}
		printf("%d\n",ans);
	}
	return 0;
//
}

