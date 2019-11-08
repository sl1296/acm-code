
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000000];
char num[1000000];
int x[8]={0,1,4,11,26,57,120,247};
int main(){
    while(gets(s)!=NULL){
        gets(num);
        int len=strlen(num);
        int p=0;
        while(1){
            int a[5];
            for(int i=0;i<3;i++){
                if(p==len){
                    gets(num);
                    len=strlen(num);
                    p=0;
                }
                a[i]=num[p]-'0';
                p++;
            }
            int d=a[0]*4+a[1]*2+a[2];
            if(d==0)break;
            while(1){
                int b[10];
                int c=0;
                bool exi=true;
                for(int i=0;i<d;i++){
                    if(p==len){
                        gets(num);
                        len=strlen(num);
                        p=0;
                    }
                    b[i]=num[p]-'0';
                    p++;
                    c=c*2+b[i];
                    if(b[i]==0)exi=false;
                }
                if(exi)break;
                int r=x[d-1]+c;
                printf("%c",s[r]);
            }
        }
        printf("\n");
    }
    return 0;
}

