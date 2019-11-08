
#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define LL long long
using namespace std ;
const LL maxn = 300005 ;
const LL mod = 1000000007 ;
vector<LL> G[maxn] ;
LL idl[maxn] ;
LL idr[maxn] ;
LL deep[maxn] ;
LL node[maxn] ;
LL cnt,n;
void add_edge(LL from,LL to){
    G[from].push_back(to) ;
}
void dfs(LL u,LL fa,LL d){
    node[u]=cnt;
    deep[cnt] = d ;
    idl[u] = cnt++;
    LL sz = G[u].size() ;
    for(LL i=0;i<sz;i++){
        dfs(G[u][i],u,d+1) ;
    }
    idr[u] = cnt-1 ;
}
LL C[maxn] ;
LL CC[maxn] ;
LL lowbit(LL x){
    return x&(-x) ;
}
void add(LL v,LL x,LL k){
    for(LL i=idl[v];i<n+4;i+=lowbit(i)){
        C[i]+=(x+deep[v]*k%mod);
        C[i]%=mod;
    }
    for(LL i=idr[v]+1;i<n+4;i+=lowbit(i)){
        C[i]-=(x+deep[v]*k%mod);
        C[i]%=mod;
    }
    for(LL i=idl[v];i<n+4;i+=lowbit(i)){
        CC[i]+=k ;
        CC[i]%=mod;
    }
    for(LL i=idr[v]+1;i<n+4;i+=lowbit(i)){
        CC[i]-=k ;
        CC[i]%=mod;
    }
    return ;
}
LL sum1(LL x){
    LL ret = 0 ;
    for(LL i=x;i>0;i-=lowbit(i)){
        ret+=C[i] ;
        ret%=mod;
    }
    return ret ;
}
LL sum2(LL x){
    LL ret = 0 ;
    for(LL i=x;i>0;i-=lowbit(i)){
        ret+=CC[i] ;
        ret%=mod;
    }
    return ret*deep[x]%mod ;
}
int main(){

    LL t ;
    scanf("%I64d",&t) ;
    while(t--){
        for(int i=0;i<maxn;i++)G[i].clear();
        memset(C,0,sizeof(C)) ;
        memset(CC,0,sizeof(CC)) ;
        memset(deep,0,sizeof(deep)) ;
        memset(node,0,sizeof(node)) ;
        memset(idl,0,sizeof(idl)) ;
        memset(idr,0,sizeof(idr)) ;

        scanf("%I64d",&n) ;
        for(LL i=2;i<=n;i++){
            LL a ;
            scanf("%I64d",&a) ;
            add_edge(a,i);
        }
        cnt=1 ;
        dfs(1,0,1) ;
        LL q ;
        scanf("%I64d",&q) ;
        while(q--){
            LL op ;
            scanf("%I64d",&op);
            if(op&1){
                LL v,x,k ;
                scanf("%I64d%I64d%I64d",&v,&x,&k) ;
                add(node[v],x,k) ;
            }else{
                LL v ;
                scanf("%I64d",&v);
                LL w = sum1(node[v])-sum2(node[v]) ;
                w=(w%mod+mod)%mod;
                printf("%I64d\n",w);

            }
        }
    }
    return 0;
}

