
#include <stdio.h>
int main(){
    char s[1010];
    int i,j;
    while(gets(s)!=NULL){
        for(i=0;s[i]!=0;i++){
            if(s[i]=='y' && s[i+1]=='o' && s[i+2]=='u'){
                s[i]='w';
                s[i+1]='e';
                for(j=i+3;s[j]!=0;j++)s[j-1]=s[j];
                s[j-1]=0;
            }
        }
        printf("%s\n",s);
    }
}

