
#include<cstdio>
int main(){
    int x;
    char s[10];
    while(~scanf("%d%s",&x,s)){
        if(s[0]=='K'){
            if(x==1){
                printf("1\n");
            }else{
                printf("4\n");
            }
        }else if(s[0]=='N'){
            if(x<3){
                printf("1\n");
            }else{
                printf("2\n");
            }
        }else if(s[0]=='B'){
            printf("%d\n",x);
        }else{
            printf("%d\n",x);
        }
    }
    return 0;
}

