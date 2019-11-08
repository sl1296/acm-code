
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==1){
            if(m&1) printf("1\n");
            else printf("2\n");
        }else if(m==1){
            if(n&1) printf("1\n");
            else printf("0\n");
        }else if(n%2==1&&m%2==1) printf("1\n");
        else if(n%2==1&&m>n)printf("2\n");
           else printf("0\n");
    }
    return 0;
}

