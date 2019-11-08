
#include<bits/stdc++.h>
using namespace std;
int x[100];
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n,xn=0;
        scanf("%d",&n);
        while(n!=1){
            if(n&1)x[xn++]=1;else x[xn++]=0;
            n>>=1;
        }
        long long p=1,q=1;
        for(int i=xn-1;i>=0;i--){
            if(x[i]){
                q+=p;
            }else{
                p+=q;
            }
        }
        printf("Case %d: %lld/%lld\n",z,q,p);
    }
    return 0;
}

