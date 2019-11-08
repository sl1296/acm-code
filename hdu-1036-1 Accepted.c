
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(){
	int n,z,end,ans1,ansm,anss,i,all,ans;
	char s[10];
	double d,ans2;
	scanf("%d%lf",&n,&d);
	while(scanf("%d",&z)!=EOF){
		end=0;
		all=0;
		for(i=0;i<n;i++){
			scanf("%s",&s);
			if(s[0]=='-')end=1;
			if(!end)all=all+(s[0]-48)*3600+(s[2]-48)*600+(s[3]-48)*60+(s[5]-48)*10+s[6]-48;
		}
		printf("%3d: ",z);
		if(end){
			printf("-\n");
		}else{
			ans2=all/d;
			ans1=ans2;
			ans=(ans2-ans1)<0.5?ans1:(ans1+1);
			ansm=ans/60;
			anss=ans-ansm*60;
			printf("%d:%02d min/km\n",ansm,anss);
		}
	}
	return 0;
}


