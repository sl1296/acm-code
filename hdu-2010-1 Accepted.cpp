
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool is[1010];
int main(){
    int s,e;
    memset(is,false,sizeof(is));
    for(int i=100;i<1000;i++){
        int a=i%10;
        int b=i/10%10;
        int c=i/100;
        if(a*a*a+b*b*b+c*c*c==i)is[i]=true;
    }
    while(scanf("%d%d",&s,&e)!=EOF){
        int c=0;
        for(int i=s;i<=e;i++){
            if(is[i]){
                if(c)printf(" ");
                printf("%d",i);
                c++;
            }
        }
        if(c==0)printf("no\n");else printf("\n");
    }
    return 0;
}

