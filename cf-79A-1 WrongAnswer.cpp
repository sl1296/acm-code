
#include <stdio.h>
#include <math.h>
int main(){
    int x,y,i=0;
    scanf("%d%d",&x,&y);
    while(1){
        if(x*100+y*10<220 || y<1)break;
        if(i%2){
            if(y>10){
                y-=11;
            }else if(y>5){
                y-=6;
                x--;
            }else{
                y--;
                x-=2;
            }
        }else{
            if(x>1){
                x-=2;
                y--;
            }else if(x==1){
                x=0;
                y-=6;
            }else{
                y-=11;
            }
        }
        i++;
    }
    if(i%2){
        printf("Ciel\n");
    }else{
        printf("Hanako\n");
    }
    return 0;
}

