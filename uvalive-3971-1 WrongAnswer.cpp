
#include<cstdio>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,int> ma;
struct po{
	char name[30];
	int type,pri,qua;
};
po li[1010];
int main(){
	int t;
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		int n,b;
		scanf("%d%d",&n,&b);
		int ty=1,mx=0;
		char in[30];
		ma.clear();
		for(int i=0;i<n;i++){
			scanf("%s%s%d%d",in,li[i].name,&li[i].pri,&li[i].qua);
			string tmp=in;
			if(ma[tmp])li[i].type=ma[tmp];
			else{
				ma[tmp]=ty;
				li[i].type=ty;
				ty++;
			}
			mx=max(mx,li[i].qua);
		}
		int s=0,e=mx,m;
		while(s<e){
			m=(s+e+1)/2;
			bool pd=true;
			int sum=0;
			for(int j=1;j<ty;j++){
				int mi=99999999;
		    	for(int i=0;i<n;i++)if(li[i].qua>=m && j==li[i].type && mi>li[i].pri)mi=li[i].pri;
		    	if(mi==mx+1){pd=false;break;}
		    	sum+=mi;
			}
			if(pd && sum<=b)s=m;
			else e=m-1;
		}
		printf("%d\n",s);
	}
	return 0;
}

