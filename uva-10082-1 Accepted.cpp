
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
char in[10010];
char s[4][50]={"`1234567890-=","QWERTYUIOP[]\\","ASDFGHJKL;'","ZXCVBNM,./"};
map<char,char> ma;
int main(){
    int a[4]={13,13,11,10};
    int i,j,l;
    for(i=0;i<4;i++){
        for(j=1;j<a[i];j++){
            ma[s[i][j]]=s[i][j-1];
        }
    }
    ma[' ']=' ';
    while(gets(in)!=NULL){
        l=strlen(in);
        for(i=0;i<l;i++)printf("%c",ma[in[i]]);
        printf("\n");
    }
    return 0;
}

