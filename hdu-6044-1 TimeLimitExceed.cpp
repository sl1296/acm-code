
#include<cstdio>
#include<algorithm>
#include<map>
#define LL long long
using namespace std;
const LL mod=1e9+7;
LL jc[1000010]={1,1},invjc[1000010],res;
int l[1000010],r,n,cas=1;
typedef pair<int,int> P;
LL C(LL n,LL k){
    return jc[n]*invjc[k]%mod*invjc[n-k]%mod;
}
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
    while(~scanf("%d",&n)){
        ma.clear();
        for(int i=1;i<=n;i++)scanf("%d",&l[i]);
        for(int i=1;i<=n;i++){
            scanf("%d",&r);
            ma[P(l[i],r)]=i;
        }
        res=1;
        dfs(1,n);
        printf("Case #%d: %lld\n",cas++,res);
    }
}

