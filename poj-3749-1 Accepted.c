
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[300],x;
    int i;
    while(1){
        gets(s);
        if(strcmp(s,"ENDOFINPUT")==0)break;
        gets(s);
        for(i=0;s[i]!=0;i++){
            if(s[i]>='A' && s[i]<='Z'){
                x=s[i]-5;
                if(x<'A')x+=26;
                printf("%c",x);
            }else{
                printf("%c",s[i]);
            }
        }
        gets(s);
        printf("\n");
    }
}

