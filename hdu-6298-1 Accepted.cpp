
#include<cstdio>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n%3==0){
            long long x=n/3;
            printf("%lld\n",x*x*x);
        }else if(n%4==0){
            long long x1=n/4,x2=n/2;
            printf("%lld\n",x1*x1*x2);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}

