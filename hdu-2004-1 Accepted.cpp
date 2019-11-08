
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int x;
    while(scanf("%d",&x)!=EOF){
        if(x>100 || x<0){
            printf("Score is error!\n");
        }else if(x>89){
            printf("A\n");
        }else if(x>79){
            printf("B\n");
        }else if(x>69){
            printf("C\n");
        }else if(x>59){
            printf("D\n");
        }else{
            printf("E\n");
        }
    }
    return 0;
}

