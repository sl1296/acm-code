
#include<cstdio>
int main(){
    int n,k;
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0&&k==0)break;
        long long ans=1;
        for(int i=1;i<=k;i++)ans=ans*(n-i+1)/i;
        printf("%d\n",(int)ans);
    }
    return 0;
}

