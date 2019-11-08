
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    double r;
    while(scanf("%lf",&r)!=EOF){
        double ans=r*r*r*4*3.1415927/3;
        printf("%.3f\n",ans);
    }
    return 0;
}

