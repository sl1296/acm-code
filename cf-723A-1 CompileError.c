
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;
int main(){
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        printf("%d\n",max(a,max(b,c))-min(a,min(b,c)));
    }
    return 0;
}

