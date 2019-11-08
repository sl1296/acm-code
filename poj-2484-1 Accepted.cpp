
#include <stdio.h>
int main(){
    int n;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        if(n<3)printf("Alice\n"); else printf("Bob\n");
    }
    return 0;
}

