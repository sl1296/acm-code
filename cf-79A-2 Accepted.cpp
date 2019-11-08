
#include <stdio.h>
#include <math.h>
int main(){
    int x,y,i=0;
    scanf("%d%d",&x,&y);
    while(1){
   //     printf("%d:%d %d\n",i,x,y);
        if(x*100+y*10<220 || y<2)break;
        if(i%2){
            if(y>21){
                y-=22;
            }else if(y>11){
                y-=12;
                x--;
            }else{
                y-=2;
                x-=2;
            }
        }else{
            if(x>1){
                x-=2;
                y-=2;
            }else if(x==1){
                x=0;
                y-=12;
            }else{
                y-=22;
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

