
#include <stdio.h>
int main(){
    int t,i,n,c;
    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%d",&n);
        c=n/5+n/25+n/125+n/625+n/3125+n/15625+n/78125+n/390625+n/1953125+n/9765625+n/48828125+n/244140625;
        printf("%d\n",c);
    }
}

