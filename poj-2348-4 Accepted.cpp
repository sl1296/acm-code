
#include <stdio.h>
int main(){
    int a,b,c,t;
    while(1){
        scanf("%d%d",&a,&b);
        if(!a && !b)break;
        if(a<b){t=a;a=b;b=t;}
        c=1;
        while(1){
            if(a%b==0 || a/b>=2)break;
            t=a;
            a=b;
            b=t-a;
            c++;
        }
        if(c&1)printf("Stan wins\n");
        else printf("Ollie wins\n");
    }
    return 0;
}

