
#include <stdio.h>
int main(){
    int a,b,c,d=1;
    scanf("%d%d",&a,&b);
    a%=b;
    c=a;
    while(c!=1){
        c=(a+c)%b;
        d++;
    }
    printf("%d\n",d);
    return 0;
}

