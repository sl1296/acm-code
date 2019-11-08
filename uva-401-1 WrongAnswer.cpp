
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
char in[25];
map<char,char> ma;
char s1[50]="ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char s2[50]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
int main(){
    int l,i;
    bool a,b;
    for(i=0;i<35;i++)ma[s1[i]]=s2[i];
    while(gets(in)!=NULL){
        a=b=true;
        l=strlen(in);
        for(i=0;i<l;i++){
            if(in[i]!=in[l-i-1]){
                a=false;
                break;
            }
        }
        for(i=0;i<l;i++){
            if(ma[in[i]]!=in[l-i-1]){
                b=false;
                break;
            }
        }
        if(a && b){
            printf("%s -- is a mirrored palindrome\n\n",in);
        }else if(a && !b){
            printf("%s -- is a regular palindrome.\n\n",in);
        }else if(!a && b){
            printf("%s -- is a mirrored string.\n\n",in);
        }else{
            printf("%s -- is not a palindrome.\n\n",in);
        }
    }
    return 0;
}

