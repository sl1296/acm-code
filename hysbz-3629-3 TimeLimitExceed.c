
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int a[5000],an;
int main(){
    int k,sum,i,j;
    while(scanf("%d",&k)!=EOF){
        an=0;
        for(i=1;i<k;i++){
            sum=0;
            for(j=1;j<=i;j++){
                if(i%j==0)sum+=j;
            }
            if(sum==k){
                a[an]=i;
                an++;
            }
        }
        printf("%d\n",an);
        for(i=0;i<an;i++){
            printf("%d",a[i]);
            if(i<an-1)printf(" ");
        }
        if(an)printf("\n");
    }
    return 0;
}

