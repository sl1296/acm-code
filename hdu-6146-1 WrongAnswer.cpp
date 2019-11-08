
#include<cstdio>
#define LL long long
const LL mod=1000000007;
LL a[10010]={0,2,24};
LL pre[10010]={0,0,6};
LL pow2[10010]={1,2,4};
int main(){
    for(int i=3;i<10005;i++)pow2[i]=pow2[i-1]*2%mod;
    for(int i=3;i<10005;i++){
        a[i]=(pre[i-1]*8%mod+2*i*pow2[i]%mod)%mod;
        pre[i]=(pre[i-1]*2%mod+pow2[i])%mod;
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;
}

