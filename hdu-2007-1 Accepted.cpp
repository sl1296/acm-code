
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y)!=EOF){
        int s,e;
        s=min(x,y);
        e=max(x,y);
        int a=0,b=0,i;
        for(i=s;i<=e;i++){
            if(i%2==1){
                b=b+i*i*i;
            }else{
                a=a+i*i;
            }
        }
        printf("%d %d\n",a,b);
    }
    return 0;
}

