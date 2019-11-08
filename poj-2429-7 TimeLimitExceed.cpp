
#include <stdio.h>
#include <math.h>
#define ll unsigned long long
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
int main(){
    ll g,l,c,i;
    while(scanf("%llu%llu",&g,&l)!=EOF){
        c=l/g;
        for(i=sqrt(c);i>0;i--){
            if(c%i==0 && gcd(i,c/i)==1)break;
        }
        printf("%llu %llu\n",i*g,l/i);
    }
    return 0;
}

