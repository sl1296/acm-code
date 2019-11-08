
#include<cstdio>
#include<algorithm>
using namespace std;
double r[10010];
double pi=3.14159265358979323846;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int f,n;
		double mx=0;
		scanf("%d%d",&n,&f);
		for(int i=0;i<n;i++){
			scanf("%lf",&r[i]);
		    r[i]=r[i]*r[i]*pi;
		    mx+=r[i];
		}
		mx/=(f+1);
		double s=0,e=mx+0.1,m;
		while(e-s>1e-5){
			m=(e+s)/2;
			int sum=0;
			for(int i=0;i<n;i++)sum+=(int)(r[i]/m);
			if(sum>f)s=m;else e=m;
		}
		printf("%.4f\n",s);
	}
	return 0;
}

