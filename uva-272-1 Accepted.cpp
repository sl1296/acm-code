
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
char s[10010];
int main(){
    int i,l,c=0;
    while(gets(s)!=NULL){
        l=strlen(s);
        for(i=0;i<l;i++){
            if(s[i]!='\"')printf("%c",s[i]);
            else{
                if(c%2){
                    printf("''");
                }else{
                    printf("``");
                }
                c++;
            }
        }
        printf("\n");
    }
    return 0;
}

