


#include<cstdio>
#define LL long long
LL a[10005]={1,1,6,12};
LL mod=1000000007;
LL pow2[10010]={1,2,4,8};
LL re[10005];
LL exgcd(LL a,LL b,LL &x,LL &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    LL q=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}
LL inv(LL a,LL n){
    LL x,y,d=exgcd(a,n,x,y);
    if(d==1)return (x%n+n)%n;
    else return -1;
}
int main(){
    for(int n=4;n<10005;n++){
        pow2[n]=pow2[n-1]*2%mod;
        a[n]=((8*n-31)*a[n-1]%mod-(4*n-19)*a[n-2]%mod-(3*n-10)*a[n-3]%mod+(2*n-10)*a[n-4]%mod)%mod*inv(3*n-11,mod)%mod;
        a[n]=(a[n]+mod)%mod;
    }
    for(int i=1;i<10005;i++){
        re[i]=a[i]*pow2[i]%mod;
        re[i]=(re[i]+mod)%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%I64d\n",re[n]);
    }
    return 0;
}



