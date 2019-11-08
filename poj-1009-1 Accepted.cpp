
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
struct node{
    ll id;
    int val;
    bool operator < (const node &p) const{
        return id<p.id;
    }
};
node in[10010];
ll inc;
ll need[100010],ncc;
ll re[100010];
ll n,all;
inline int gt(ll tmp){
    return in[upper_bound(in,in+inc,(node){tmp,0})-in-1].val;
}
inline ll cal(ll pos){
    ll row=pos/n,col=pos%n;
    ll ret=0;
    for(ll i=row-1;i<=row+1;i++){
        if(i<0||i>=all)continue;
        for(ll j=col-1;j<=col+1;j++){
            if(j<0||j>=n)continue;
            ret=max(ret,(ll)abs(gt(row*n+col)-gt(i*n+j)));
        }
    }
    return ret;
}
int main(){
    while(1){
        scanf("%lld",&n);
        if(!n)break;
        inc=ncc=0;
        ll pos=0;
        while(1){
            ll u,v;
            scanf("%lld%lld",&u,&v);
            if(!u&&!v)break;
            for(int i=pos-n;i<=pos+n;i+=n){
                for(int j=-1;j<=1;j++){
                    if(i+j>=0)need[ncc++]=i+j;
                }
            }
            in[inc++]=(node){pos,u};
            pos+=v;
        }
        need[ncc++]=pos-n;
        all=pos/n;
        sort(need,need+ncc);
        ncc=unique(need,need+ncc)-need;
        while(need[ncc-1]>=pos)ncc--;
        for(int i=0;i<ncc;i++){
            re[i]=cal(need[i]);
        }
        ll now=re[0],pre=0;
        printf("%lld\n",n);
        for(int i=1;i<ncc;i++){
            if(re[i]!=now){
                printf("%lld %lld\n",now,need[i]-pre);
                now=re[i];
                pre=need[i];
            }
        }
        printf("%lld %lld\n0 0\n",now,pos-pre);
    }
    printf("0\n");
    return 0;
}

