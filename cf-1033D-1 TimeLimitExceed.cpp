
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const int Times=10;
LL ct,fac[10010];
LL gcd(LL a,LL b){
    return b?gcd(b,a%b):a;
}
LL multi(LL a,LL b,LL m){
    LL ans=0;
    while(b){
        if(b&1){
            ans=(ans+a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}
LL quick_mod(LL a,LL b,LL m){
    LL ans=1;
    a%=m;
    while(b){
        if(b&1){
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}
bool Miller_Rabin(LL n){
    if(n==2)return true;
    if(n<2 || !(n&1))return false;
    LL a,m=n-1,x,y;
    int k=0;
    while((m&1)==0){
        k++;
        m>>=1;
    }
    for(int i=0;i<Times;i++){
        a=rand()%(n-1)+1;
        x=quick_mod(a,m,n);
        for(int j=0;j<k;j++){
            y=multi(x,x,n);
            if(y==1&&x!=1 && x!=n-1)return false;
            x=y;
        }
        if(y!=1)return false;
    }
    return true;
}
LL Pollard_rho(LL n,LL c){
    LL x,y,d,i=1,k=2;
    y=x=rand()%(n-1)+1;
    while(true){
        i++;
        x=(multi(x,x,n)+c)%n;
        d=gcd((y-x+n)%n,n);
        if(1<d&&d<n)return d;
        if(y==x)return n;
        if(i==k){
            y=x;
            k<<=1;
        }
    }
}
void find(LL n,int c){
    if(n==1)return;
    if(Miller_Rabin(n)){
        fac[ct++]=n;
        return;
    }
    LL p=n;
    LL k=c;
    while(p>=n)p=Pollard_rho(p,c--);
    find(p,k);
    find(n/p,k);
}
const LL mod=998244353;
int main(){
    int n;
    scanf("%d",&n);
    ct=0;
    for(int i=0;i<n;++i){
        LL x;
        scanf("%I64d",&x);
        find(x,60);
    }
    sort(fac,fac+ct);
    LL ans=1;
    for(int i=0;i<ct;++i){
        LL now=2;
        while(i+1<ct && fac[i+1]==fac[i])++i,++now;
        ans=ans*now%mod;
    }
    printf("%I64d\n",ans);
    fflush(stdout);
    return 0;
}

