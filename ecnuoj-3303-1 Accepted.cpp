
#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        ull a,b;
        scanf("%llu%llu",&a,&b);
        for(int i=0;i<64;i++){
            if(!((a>>i)&((ull)1))){
                ull c=a|(((ull)1)<<i);
                if(c<=b)a=c;else break;
            }
        }
        printf("Case %d: %llu\n",z,a);
    }
}

