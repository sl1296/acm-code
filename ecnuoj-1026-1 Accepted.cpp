
#include<cstdio>
#include<cmath>
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;n--;
        double h=1.75+(n<3?n*5:n*3+4);
        h=sqrt(h*2/9.8);
        printf("%.3f\n",h);
    }
    return 0;
}

