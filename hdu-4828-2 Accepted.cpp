
#include <cstdio>
#define ll __int64
#define mod 1000000007
ll jc[2000010],res[1000010];
void exgcd(__int64 a,__int64 b,__int64 &x,__int64 &y){
    if (b==0){
        x=1,y=0;
        return;
    }
    exgcd(b,a%b,y,x);
    y-=a/b*x;
}
int main(){
    int n,t,i,z;
    ll a,b;
    jc[0]=1;
    for(i=1;i<2000005;i++)jc[i]=(jc[i-1]*i)%mod;
    for(i=1;i<1000005;i++){
        exgcd(jc[i],mod,a,b);
        res[i]=(a%mod+mod)%mod;
    }
    scanf("%d",&t);
    for(z=1;z<=t;z++){
        scanf("%d",&n);
        a=jc[n+n]*res[n+1]%mod*res[n]%mod;
        printf("Case #%d:\n%I64d\n",z,a);
    }
}

