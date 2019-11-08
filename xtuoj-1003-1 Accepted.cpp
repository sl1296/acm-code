
#include <stdio.h>
int main(){
    int a,b=1,i;
    scanf("%d",&a);
    for(i=2;i<=a;i++)b*=i;
    printf("%d",b);
    return 0;
}

