
#include <stdio.h>
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    char s[10];
    int a,b,c,d,r1,r2,g;
    while(scanf("%s",s)!=EOF){
        a=s[0]-48;
        b=s[2]-48;
        c=s[4]-48;
        d=s[6]-48;
        r2=b*d;
        if(s[3]=='+')r1=a*d+b*c;
        else r1=a*d-b*c;
        if(r1==0){
            printf("0\n");
            continue;
        }
        if(r1<0){
            printf("-");
            r1=-r1;
        }
        g=gcd(r1,r2);
        r1/=g;
        r2/=g;
        if(r2==1)printf("%d\n",r1);
        else printf("%d/%d\n",r1,r2);
    }
}

