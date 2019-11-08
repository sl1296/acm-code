
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char s[300],s2[300],x[300];
    int i,j,l,l2,lx;
    while(gets(s)!=NULL){
        l=strlen(s);
        while(1){
            gets(s2);
            if(strcmp(s2,"END")==0)break;
            if(strcmp(s2,"NULL")==0){
                printf("0 NULL\n%d\n",strcmp(s2,"NULL"));
                continue;
            }
            l2=strlen(s2);
            for(i=0;i<l;i++){
                for(j=0;j<l2;j++){
                    if(s[i+j]!=s2[j])break;
                }
                if(j>=l2)break;
            }
            strcpy(x,s);
            x[i]=0;
            lx=strlen(x);
            if(lx){
                printf("%d %s\n",lx,x);
            }else{
                printf("0 NULL\n");
            }
        }
    }
}

