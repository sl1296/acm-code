
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char s[10];
    while(scanf("%s",s)!=EOF){
        sort(s,s+3);
        for(int i=0;i<3;i++){
            if(i)printf(" ");
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return 0;
}

