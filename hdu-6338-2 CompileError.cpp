
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
typedef long long ll;
#define maxn 1000010
#define mod 1000000007
struct node {
    int y,next;
} e[maxn*2];
int fac[maxn];
unordered_map<pp,int> mp;
int B[maxn],len,Link[maxn];
void insert(int x,int y) {
    e[++len].next=Link[x];
    Link[x]=len;
    e[len].y=y;
}
int getnum(int root,int fa){
    if(mp.count(make_pair(root,fa))) return mp[make_pair(root,fa)];
    ll ans=1;
    int cnt=0;
    for(int i=Link[root]; i; i=e[i].next){
        int y=e[i].y;
        if(y==fa) continue;
        cnt++;
        ans=ans*getnum(y,root)%mod;
    }
    ans=ans*fac[cnt]%mod;
    return mp[make_pair(root,fa)]=ans;
}
int dfs(int root,int fa,int rn){
    ll ans=1;
    int cnt=0;
    bool flag=false,yes=false;
    for(int i=Link[root]; i; i=e[i].next){
        int y=e[i].y;
        if(y==fa) continue;
        yes=true;
        if(y==B[rn+1]) flag=true;
        if(y<B[rn+1]){
            cnt++;
            ans=ans*getnum(y,root)%mod;
        }
    }
    if(!yes) return 0;
    if(!flag){
        if(!cnt) return 0;
        return ans*fac[cnt]%mod;
    }
    else{
        return (ans*fac[cnt]%mod+dfs(B[rn+1],root,rn+1))%mod;
    }
}
int main(){
    int ca;
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=(ll)fac[i-1]*i%mod;
    scanf("%d",&ca);
    while(ca--){
        mp.clear();
        int n,u,v;
        scanf("%d",&n);
        Link[n]=len=0;
        B[n]=-1;
        for(int i=0;i<n;i++){
            scanf("%d",&B[i]);
            Link[i]=0;
        }
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            insert(u,v);
            insert(v,u);
        }
        int ans=0;
        for(int i=1;i<B[0];i++){
            ans=(ans+getnum(i,0))%mod;
        }
        printf("%d\n",(ans+dfs(B[0],0,0))%mod);
    }
    return 0;
}

