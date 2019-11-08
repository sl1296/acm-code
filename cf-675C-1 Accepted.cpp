
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<__int64, int> ss;
int main(){
    int i,n,x,re=0;
    __int64 s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        s=s+x;
        ss[s]++;
        if(re<ss[s])re=ss[s];
    }
    printf("%d\n",n-re);
    return 0;
}

