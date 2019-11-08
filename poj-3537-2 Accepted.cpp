
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int sg[2010];
int g(int x){
    int i;
    int bo[2010];
    if(x<0)return 0;
    if(sg[x]!=-1)return sg[x];
    memset(bo,0,sizeof(bo));
    for(i=1;i<=x;i++)bo[g(i-3)^g(x-i-2)]=1;
    for(i=0;;i++)if(!bo[i])return sg[x]=i;
}
int main(){
    int n;
    memset(sg,-1,sizeof(sg));
    while(scanf("%d",&n)!=EOF){
        if(g(n))printf("1\n"); else printf("2\n");
    }
    return 0;
}

