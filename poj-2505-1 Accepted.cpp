
#include <stdio.h>
#include <math.h>
int main(){
    long long n,x;
    while(scanf("%lld",&n)!=EOF){
        for(x=0;n>1;x++){
            if(x&1)n=ceil(n/2.0);
            else n=ceil(n/9.0);
        }
        puts(x&1?"Stan wins.":"Ollie wins.");
    }
	return 0;
}


