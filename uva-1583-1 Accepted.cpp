
#include<cstdio>
int e[100100];
int main(){
    int n,x,i;
    for(i=1;i<100000;i++){
        x=i;
        n=0;
        while(x){
            n+=x%10;
            x/=10;
        }
        n+=i;
        if(!e[n])e[n]=i;
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        printf("%d\n",e[x]);
    }
    return 0;
}

