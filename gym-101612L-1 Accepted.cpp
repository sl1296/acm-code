
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const int Times=10;
const LL INF=(LL)1<<61;
const int N=550;
LL n,ct;
LL fac[N];
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
LL facc[N],facn[N],ctt;
LL ansx[1000010];
int xc1[1000010],xc2[1000010],ax;
void dfs(LL x,int i)
{
    if(i==ctt){
        if(x==1)return;
        LL tmp=n;
        int c1=0,c2=0;
        while(tmp%x==0){
            ++c1;
            tmp/=x;
        }
        ++x;
        while(tmp%x==0){
            ++c2;
            tmp/=x;
        }
        if(tmp==1){
            ansx[ax]=x-1;
            xc1[ax]=c1;
            xc2[ax++]=c2;
        }
        return;
    }
    for(int j=0;j<=facn[i];++j){
        dfs(x,i+1);
        x*=facc[i];
    }
}
int main(){
    freopen("little.in","r",stdin);
    freopen("little.out","w+",stdout);
    while(~scanf("%lld",&n)){
        bool hv=false;
        for(int i=0;i<63;++i){
            if((1LL<<i)==n){
                printf("-1\n");
                hv=true;
                break;
            }
        }
        if(hv)continue;
        find(n,120);
        sort(fac,fac+ct);
        ctt=0;
        for(int i=0;i<ct;++i){
            facn[ctt]=1;
            while(i+1<ct && fac[i+1]==fac[i])++i,++facn[ctt];
            facc[ctt++]=fac[i];
        }
        ax=0;
        dfs(1,0);
        printf("%d\n",ax);
        for(int i=0;i<ax;++i){
            printf("%d",xc1[i]+xc2[i]);
            for(int j=0;j<xc1[i];++j){
                printf(" %lld",ansx[i]);
            }
            for(int j=0;j<xc2[i];++j){
                printf(" %lld",ansx[i]+1);
            }
            printf("\n");
        }
    }
    return 0;
}

