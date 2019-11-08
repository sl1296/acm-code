
#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int base=1;
    bool use=false;
    while(n>3){
        int cnt=(n+1)/2;
        for(int i=0;i<cnt;++i){
            if(!use)use=true;
            else printf(" ");
            printf("%d",base);
        }
        base*=2;
        n/=2;
    }
    if(use)printf(" ");
    if(n==1){
        printf("%d\n",base);
    }else if(n==2){
        printf("%d %d\n",base,base*2);
    }else{
        printf("%d %d %d\n",base,base,base*3);
    }
    return 0;
}

