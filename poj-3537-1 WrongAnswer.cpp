
#include <stdio.h>
int s[2010];
int main(){
    int n,i,k=4;
    scanf("%d",&n);
    for(i=6;i<2001;i+=k){
        s[i]=1;
        k+=2;
    }
    if(s[n])printf("2\n");
    else printf("1\n");
}

