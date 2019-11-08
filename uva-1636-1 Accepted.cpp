
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[110];
int main(){
    int l,i;
    double p1,p2,c00,c;
    while(scanf("%s",s)!=EOF){
        c00=c=0;
        l=strlen(s);
        for(i=0;i<l-1;i++){
            if(s[i]=='0'){
                c++;
                if(s[i+1]=='0')c00++;
            }
        }
        if(s[l-1]=='0'){
            c++;
            if(s[0]=='0')c00++;
        }
        p1=c00/c;
        p2=c/l;
        if(p1>p2){
            printf("SHOOT\n");
        }else if(p1==p2){
            printf("EQUAL\n");
        }else{
            printf("ROTATE\n");
        }
    }
    return 0;
}

