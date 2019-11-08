
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 10000010
ll inv[maxn],fac[maxn];
int main(){
    ll n,p,r;
    scanf("%I64d%I64d%I64d",&n,&p,&r);
    inv[0]=inv[1]=1;
    fac[0]=fac[1]=1;
    for(int i=2;i<p;i++){
        fac[i]=fac[i-1]*i%p;
        inv[i]=(p-p/i)*inv[p%i]%p;
    }
    if(p==2){
        if(r==0&&n>2) printf("3 1\n");
        else if(r==1&&n<=3) printf("2 1\n");
        else printf("-1 -1\n");
    }else if(r==0){
        if(n>=p) printf("2 1\n");
        else printf("-1 -1\n");
    }else{
        if(n>=2*p) printf("-1 -1\n");
        else if(n>=p){
            ll f1=fac[p-1],f2=fac[n%p];
            ll tmp=r*inv[f1*f2%p]%p;
            if(tmp<p) printf("%I64d %I64d\n",p,tmp);
            else printf("-1 -1\n");
        }else{
            int a=-1,b=-1;
            ll kk=r*inv[fac[n]]%p;
            for(int i=2;i<=n;i++){
                ll k=kk*i%p;
                if(k<i){
                    a=i;b=k;break;
                }
            }
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}

