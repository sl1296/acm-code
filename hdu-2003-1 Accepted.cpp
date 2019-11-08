
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
        double ans=fabs(r);
        printf("%.2f\n",ans);
    }
    return 0;
}

