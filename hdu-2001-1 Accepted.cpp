
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    double x1,y1,x2,y2;
    while(scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2)!=EOF){
        double r=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        printf("%.2f\n",r);
    }
    return 0;
}

