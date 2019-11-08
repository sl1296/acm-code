
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
struct no{
	int x,y;
    bool operator < (const no &p) const{
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
};
no in[9];
int main(){
    int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		in[0].x=min(a,b);
		in[0].y=max(a,b);
		for(int i=1;i<6;i++){
			scanf("%d%d",&a,&b);
			in[i].x=min(a,b);
			in[i].y=max(a,b);
		}
		sort(in,in+6);
		if(in[0].x==in[1].x && in[0].y==in[1].y && in[2].x==in[3].x && in[2].y==in[3].y && in[4].x==in[5].x && in[4].y==in[5].y){
			if(in[0].x==in[2].x && in[0].y==in[4].x && in[2].y==in[4].y){
				printf("POSSIBLE\n");
			}else{
				printf("IMPOSSIBLE\n");
			}
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

