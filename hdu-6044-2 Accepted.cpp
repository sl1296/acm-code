
#include<cstdio>
#include<bits/stdc++.h>
#include<algorithm>
#include<map>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL jc[1000010]={1,1},invjc[1000010],res;
int l[1000010],r,n,cas=1;
inline char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline bool rea(int & x)
{
    char c=nc();x=0;
    if(c==EOF)    return false;
    for(;c>'9'||c<'0';c=nc());
    for(;c>='0'&&c<='9';x=x*10+c-'0',c=nc());
    return true;
}
LL C(LL n,LL k){
    return jc[n]*invjc[k]%mod*invjc[n-k]%mod;
}
typedef pair<int,int> P;
map<P,int> ma;
void dfs(int L,int R){
    if(res==0||R<L)return;
    int x=ma[P(L,R)];
    if(x==0){
        res=0;
        return;
    }
    if(L==R)return;
    res=res*C(R-L,x-L)%mod;
    dfs(L,x-1);
    dfs(x+1,R);
}
int main(){
    for(int i=2;i<1000001;i++)jc[i]=jc[i-1]*i%mod;
    invjc[1000000]=397802501;
    for(int i=1000000;i>0;i--)invjc[i-1]=invjc[i]*i%mod;
    while(rea(n)){
        ma.clear();
        for(int i=1;i<=n;i++)rea(l[i]);
        for(int i=1;i<=n;i++){
            rea(r);
            ma[P(l[i],r)]=i;
        }
        res=1;
        dfs(1,n);
        printf("Case #%d: %lld\n",cas++,res);
    }
    return 0;
}

