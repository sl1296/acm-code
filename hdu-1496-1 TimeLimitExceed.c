
#include <stdio.h>
#include <math.h>
int main(){
	int a,b,c,d,x1,x2,x3,x4,l1,l2,l3,count,t2;
	double t;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF){
		count=0;
		for(x1=1;x1<101;x1++){
			l1=a*x1*x1;
			for(x2=1;x2<101;x2++){
				l2=b*x2*x2;
				for(x3=1;x3<101;x3++){
					l3=c*x3*x3+l2+l1;
					if(l3*d>0)continue;
					t=sqrt(-(double)l3/(double)d);
					t2=t;
					if(t2==t && t2<101)count++;
				}
			}
		}
		count*=16;
		printf("%d\n",count);
	}
	return 0;
}

