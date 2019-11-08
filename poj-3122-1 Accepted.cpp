
#include <stdio.h>
#include <math.h>
#define N 10000
#define EPS 1e-5
double pie[N],PI;
int main(){
    int n,f,ca,i,j,t;
    double lt,rt,mid;
    double PI = acos(-1.0);
    scanf("%d",&ca);
    while(ca--){
    	scanf("%d %d",&n,&f);
    	rt = -1.0;
    	for(i=0;i<n;i++){
    		scanf("%lf",pie+i);
    		pie[i] *= pie[i]*PI;
    		if(pie[i]- rt > EPS) rt = pie[i];
    	}
    	lt = 0;
    	while(rt-lt > EPS){
    		mid = (lt+rt)/2.0;
    		t = -f-1;
    		for(i=0;i<n;i++) t += (int)(pie[i]/mid);
    		if(t>=0) lt = mid;
    		else rt = mid;
    	}
    	printf("%.4f\n",mid);
    }
    return 0;
}

