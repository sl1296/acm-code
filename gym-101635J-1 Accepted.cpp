
#include<cstdio>
int main(){
    int n;
    while(~scanf("%d",&n)){
        long long x[3]={0},a;
        for(int i=1;i<=n;++i){
            scanf("%lld",&a);
            x[i%3]+=a;
        }
        long long r[3]={0};
        for(int i=1;i<=n;++i){
            scanf("%lld",&a);
            if(i%3==0){
                r[0]+=a*x[0];
                r[1]+=a*x[1];
                r[2]+=a*x[2];
            }else if(i%3==1){
                r[0]+=a*x[2];
                r[1]+=a*x[0];
                r[2]+=a*x[1];
            }else{
                r[0]+=a*x[1];
                r[1]+=a*x[2];
                r[2]+=a*x[0];
            }
        }
        printf("%lld %lld %lld\n",r[0],r[1],r[2]);
    }
    return 0;
}

