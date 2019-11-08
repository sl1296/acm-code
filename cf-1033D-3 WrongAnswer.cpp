
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
ll x[1000],c[1000];
ll fja[10000],fjac;
ll fjb[10000],fjbn[10000],fjbc;
const ll mod=998244353;
int main(){
    int n,nn=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%I64d",&x[i]);
    }
    sort(x,x+n);
    for(int i=0;i<n;++i){
        int now=1;
        while(i+1<n && x[i+1]==x[i])++i,++now;
        x[nn]=x[i];c[nn++]=now;
    }
    for(int i=0;i<nn;++i){
        ll s=1,e=37610,mid;
        while(e>s){
            mid=e-(e-s)/2;
            if(mid*mid*mid*mid>x[i])e=mid-1;
            else s=mid;
        }
        if(s*s*s*s==x[i]){
            for(int u=0;u<c[i];++u){
                fja[fjac++]=s;
                fja[fjac++]=s;
                fja[fjac++]=s;
                fja[fjac++]=s;
            }
            continue;
        }
        s=1,e=1260000,mid;
        while(e>s){
            mid=e-(e-s)/2;
            if(mid*mid*mid>x[i])e=mid-1;
            else s=mid;
        }
        if(s*s*s==x[i]){
            for(int u=0;u<c[i];++u){
                fja[fjac++]=s;
                fja[fjac++]=s;
                fja[fjac++]=s;
            }
            continue;
        }
        s=1,e=2e9,mid;
        while(e>s){
            mid=e-(e-s)/2;
            if(mid*mid>x[i])e=mid-1;
            else s=mid;
        }
        if(s*s==x[i]){
            for(int u=0;u<c[i];++u){
                fja[fjac++]=s;
                fja[fjac++]=s;
            }
            continue;
        }
        bool fin=false;
        for(int j=0;j<fjac;++j){
            ll gcd=__gcd(fja[j],x[i]);
            if(gcd>1){
                for(int u=0;u<c[i];++u){
                    fja[fjac++]=gcd;
                    fja[fjac++]=x[i]/gcd;
                }
                fin=true;
                break;
            }
        }
        if(fin)continue;
        for(int j=0;j<fjbc;++j){
            ll gcd=__gcd(fjb[j],x[i]);
            if(gcd>1){
                swap(fjb[fjbc-1],fjb[j]);
                swap(fjbn[fjbc-1],fjbn[j]);
                for(int u=0;u<fjbn[fjbc-1];++u){
                    fja[fjac++]=gcd;
                    fja[fjac++]=fjb[fjbc-1]/gcd;
                }
                for(int u=0;u<c[i];++u){
                    fja[fjac++]=gcd;
                    fja[fjac++]=x[i]/gcd;
                }
                --fjbc;
                fin=true;
                break;
            }
        }
        if(fin)continue;
        fjbn[fjbc]=c[i];
        fjb[fjbc++]=x[i];
    }
    sort(fja,fja+fjac);
    ll ans=1;
    for(int i=0;i<fjac;++i){
        ll now=2;
        while(i+1<fjac && fja[i+1]==fja[i])++i,++now;
        ans=ans*now%mod;
    }
    for(int i=0;i<fjbc;++i){
        ans=ans*(fjbn[i]+1)*(fjbn[i]+1)%mod;
    }
    printf("%I64d\n",ans);
    return 0;
}

