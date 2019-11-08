
#include<cstdio>
#include<cmath>
int main(){
    double a,b;
    while(~scanf("%lf%lf",&a,&b)){
        double c=sqrt(a*a+b*b);
        printf("%.3f\n",c);
    }
}

