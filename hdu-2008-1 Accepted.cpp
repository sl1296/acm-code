
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        int a=0,b=0,c=0;
        double x;
        for(int i=0;i<n;i++){
            scanf("%lf",&x);
            if(x==0)b++;
            else if(x>0)c++;
            else a++;
        }
        printf("%d %d %d\n",a,b,c);
    }
    return 0;
}

