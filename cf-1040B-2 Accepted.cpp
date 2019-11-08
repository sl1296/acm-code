
#include<cstdio>
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    if(n==1){
        printf("1\n1\n");
        return 0;
    }
    int len=k*2+1;
    int num=(n+len-1)/len;
    int res=n%len;
    printf("%d\n",num);
    if(res==0){
        for(int i=k+1;i<=n;i+=len){
            if(i!=k+1)printf(" ");
            printf("%d",i);
        }
        printf("\n");
    }else{
        res+=len;
        int le=res/2,dec=len-le;
        for(int i=k+1-dec;i<=n;i+=len){
            if(i!=k+1-dec)printf(" ");
            printf("%d",i);
        }
        printf("\n");
    }
    return 0;
}

