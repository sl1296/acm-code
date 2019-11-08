
#include<cstdio>
int main(){
    int h,c;
    while(~scanf("%d%d",&h,&c)){
        if(h>c){
            printf("%d\n",h);
        }else{
            printf("%d\n",c+1);
        }
    }
    return 0;
}

