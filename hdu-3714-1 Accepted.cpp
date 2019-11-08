
#include <stdio.h>
#include <math.h>
double EPS = 1e-9;
#define N 10010
const double c1 = 0.61803398874989484820458683436564;
int a[N],b[N],c[N];
int n;

double func(double x){
	int i;
	double max = -1e10,f;
	for(i=0;i<n;i++){
		f = a[i]*x*x+b[i]*x+c[i];
		if(f - max > EPS) max = f;
	}
	return max;
}

double ts(double l,double r){
	double m1,m2,t;
	t = (r-l)*c1;
	m1 = func(r - t);
	m2 = func(l + t);
	while(fabs(r-l)>EPS){
		if(m2-m1 > EPS){
			r = l+t;
			m2 = m1;
			t = t*c1;
			m1 = func(r-t);
		}
		else{
			l = r-t;
			m1 = m2;
			t = t*c1;
			m2 = func(l+t);
		}
	}
	return m1;
}

int main(){
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        for(j=0;j<n;j++){
            scanf("%d%d%d",&a[j],&b[j],&c[j]);
        }
        printf("%.4f\n",ts(0,1000));
    }
}

