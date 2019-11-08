
/*
"Can\u0027t compile file:
program.cpp: In function \u0027int main()\u0027:
program.cpp:6:23: error: \u0027abs\u0027 was not declared in this scope
         r\u003dn*(n-abs(a-d)-abs(b-c));
                       ^
"
*/
#include <stdio.h>
#include <math.h>
int main(){
    __int64 a,b,c,d,n,r;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&n,&a,&b,&c,&d)!=EOF){
        r=n*(n-abs(a-d)-abs(b-c));
        printf("%I64d\n",r);
    }
    return 0;
}

