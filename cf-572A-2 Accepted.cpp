
#include <stdio.h>
int a[100100],b[100100];
int main(){
    int na,nb,x,y,i;
    scanf("%d%d%d%d",&na,&nb,&x,&y);
    for(i=0;i<na;i++)
        scanf("%d",&a[i]);
        for(i=0;i<nb;i++)scanf("%d",&b[i]);
        if(a[x-1]<b[nb-y]){
            printf("Yes\n");
        }else{printf("No\n");
        }

}

