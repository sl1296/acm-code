
#include <stdio.h>
int main(){
    double a,b,c;
    double p;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF){
        p=a/(a+b)*b/(a+b-c-1)+b/(a+b)*(b-1)/(a+b-c-1);
        printf("%.5lf\n",p);
    }
    return 0;
}

