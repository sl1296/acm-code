
#include <stdio.h>
#include <string.h>
#include <Stdlib.h>
#include <math.h>
int a[100100];
int c;
int main(){
    int m,i,l;
    scanf("%d",&m);
    for(i=1;c<100001;i++){
        l=1;
        if(i%5==0)l++;
        if(i%25==0)l++;
        if(i%125==0)l++;
        if(i%625==0)l++;
        if(i%3125==0)l++;
        if(i%15625==0)l++;
        if(i%78125==0)l++;
        c+=l;
        a[c]=i;
    }
    if(a[m]){
        printf("5\n");
        for(i=0;i<5;i++)printf("%d ",5*a[m]+i);
        printf("\n");
    }else{
        printf("0\n");
    }
    return 0;
}

