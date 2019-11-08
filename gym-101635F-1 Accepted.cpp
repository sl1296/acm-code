
#include<cstdio>
int main(){
    long long w,n;
    while(~scanf("%lld%lld",&w,&n)){
        long long sum=0,x,y;
        for(int i=0;i<n;++i){
            scanf("%lld%lld",&x,&y);
            sum+=x*y;
        }
        printf("%lld\n",sum/w);
    }
    return 0;
}

