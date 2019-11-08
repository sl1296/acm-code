
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        long long ans=1,a;
        for(int i=0;i<n;i++){
            scanf("%I64d",&a);
            if(a%2==1)ans*=a;

        }
        printf("%I64d\n",ans);
    }
    return 0;
}

