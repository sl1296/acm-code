
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        double x=n;
        double ans=x;
        for(int i=1;i<m;i++){
            x=sqrt(x);
            ans+=x;
        }
        printf("%.2f\n",ans);
    }
    return 0;
}

