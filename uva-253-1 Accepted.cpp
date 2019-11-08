
#include <stdio.h>
#include <string.h>
char s[12];
int sort(char up,char down,char a,char b,char c,char d){
    if ((up==s[6])&&(down==s[11])&&(a==s[7])&&(b==s[8])&&(c==s[9])&&(d==s[10]))return 1;
    if ((up==s[6])&&(down==s[11])&&(c==s[7])&&(a==s[8])&&(d==s[9])&&(b==s[10]))return 1;
    if ((up==s[6])&&(down==s[11])&&(d==s[7])&&(c==s[8])&&(b==s[9])&&(a==s[10]))return 1;
    if ((up==s[6])&&(down==s[11])&&(b==s[7])&&(d==s[8])&&(a==s[9])&&(c==s[10]))return 1;
    return 0;
}
int main(){
    int f1,f2,f3,f4,f5,f6;
    while (scanf("%s",&s)!=EOF){
        f1=sort(s[0],s[5],s[1],s[2],s[3],s[4]);
        f2=sort(s[1],s[4],s[2],s[0],s[5],s[3]);
        f3=sort(s[2],s[3],s[1],s[5],s[0],s[4]);
        f4=sort(s[5],s[0],s[1],s[3],s[2],s[4]);
        f5=sort(s[4],s[1],s[3],s[0],s[5],s[2]);
        f6=sort(s[3],s[2],s[1],s[0],s[5],s[4]);
        if(f1+f2+f3+f4+f5+f6)printf("TRUE\n");else printf("FALSE\n");
    }
    return 0;
}

