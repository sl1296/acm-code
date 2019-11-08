
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int t,x,y,z;
    int l;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&x,&y,&z);
        if(2*y-x<=0){
            printf("%d\n",z);
            continue;
        }
        if(2*x-y<=0){
            printf("0\n");
            continue;
        }
        l=z*(2*x-y);
        l=l/(x+y);
        printf("%d\n",l);
    }
}


