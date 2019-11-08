
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int n;
        scanf("%d",&n);
        if(n<16){
            if(n>6&&n%2==1){
                printf("Case #%d: Panda\n",z);
            }else{
                printf("Case #%d: Draw\n",z);
            }
        }else{
            if(n&1)printf("Case #%d: Panda\n",z);
            else printf("Case #%d: Sheep\n",z);
        }
    }
    return 0;
}

