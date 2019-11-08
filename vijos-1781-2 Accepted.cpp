
#include <stdio.h>
int gcd(int a,int b,int &x,int &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    int q=gcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}

int main(){
    int a,b,x,y;
    scanf("%d%d",&a,&b);
    gcd(a,b,x,y);
    x=(x%b+b)%b;
    printf("%d\n",x);
    return 0;
}


