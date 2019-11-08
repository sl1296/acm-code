
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;++z){
        int n;
        scanf("%d",&n);
        if(n>6&&n%2==1){
            printf("Case #%d: Panda\n",z);
        }else{
            printf("Case #%d: Draw\n",z);
        }
    }
    return 0;
}

