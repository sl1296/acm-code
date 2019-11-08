
#include <bits/stdc++.h>
#define ll long long
const ll mod=1e9+7;
using namespace std;
ll xc[200010],yc[200010];
ll xs[200010],ys[200010];
ll addx,addy;
map<pair<int,int>,bool> ma;
int main(){
    addx=addy=0;
    int n,k,q,x,y;
    scanf("%d%d%d",&n,&k,&q);
    ll all=(n*2-1)%mod,ans=all*all%mod*n%mod*n%mod;
    for(int i=1;i<=n;++i){
        xc[i]=yc[i]=n;
        xs[i]=ys[i]=all*n%mod;
    }
    while(k--){
        scanf("%d%d",&x,&y);
        ll cp=(xc[x]+yc[y]-1+mod)%mod;
        ans=((ans-2*(xs[x]+addx+ys[y]+addy-cp)%mod+all)%mod+mod)%mod;
        ma[make_pair(x,y)]=true;
        xc[x]=(xc[x]-1+mod)%mod;yc[y]=(yc[y]-1+mod)%mod;
        xs[x]=(xs[x]-n+1+mod)%mod;ys[y]=(ys[y]-n+1+mod)%mod;
        addx=(addx-1+mod)%mod;addy=(addy-1+mod)%mod;
    }
    printf("%lld\n",ans);
    while(q--){
        scanf("%d%d",&x,&y);
        if(!ma[make_pair(x,y)]){
            ll cp=(xc[x]+yc[y]-1+mod)%mod;
            ans=((ans-2*(xs[x]+addx+ys[y]+addy-cp)%mod+all)%mod+mod)%mod;
            ma[make_pair(x,y)]=true;
            xc[x]=(xc[x]-1+mod)%mod;yc[y]=(yc[y]-1+mod)%mod;
            xs[x]=(xs[x]-n+1+mod)%mod;ys[y]=(ys[y]-n+1+mod)%mod;
            addx=(addx-1+mod)%mod;addy=(addy-1+mod)%mod;
        }else{
            ll cp=(xc[x]+yc[y])%mod;
            ans=((ans+2*(xs[x]+addx+ys[y]+addy-cp)%mod+all)%mod+mod)%mod;
            ma[make_pair(x,y)]=false;
            xc[x]=(xc[x]+1)%mod;yc[y]=(yc[y]+1)%mod;
            xs[x]=(xs[x]+n-1)%mod;ys[y]=(ys[y]+n-1)%mod;
            addx=(addx+1)%mod;addy=(addy+1)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

