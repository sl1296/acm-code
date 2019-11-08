
#include<cstdio>
int main(){
    for(int i=1000;i<=9999;i++){
        int a=i/1000;
        int b=i%1000/100;
        int c=i%100/10;
        int d=i%10;
        if(a*a*a*a+b*b*b*b+c*c*c*c+d*d*d*d==i){
            printf("%d\n",i);
        }
    }
    return 0;
}

