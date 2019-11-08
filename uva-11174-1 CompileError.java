
/*
Main.java:1: error: illegal character: '#'
#include
^
Main.java:1: error: class, interface, or enum expected
#include
        ^
Main.java:2: error: illegal character: '#'
#include
^
Main.java:3: error: illegal character: '#'
#include
^
Main.java:4: error: illegal character: '#'
#include
^
Main.java:5: error: illegal character: '#'
#define ll long long
^
Main.java:7: error: class, interface, or enum expected
vector tree[40005];
^
Main.java:8: error: class, interface, or enum expected
int num[40005];
^
Main.java:9: error: class, interface, or enum expected
ll jc[40005],ny[40005];
^
Main.java:10: error: class, interface, or enum expected
const ll mod=1000000007;
^
Main.java:11: error: class, interface, or enum expected
bool vis[40005];
^
Main.java:12: error: class, interface, or enum expected
int dfs(int x){
^
Main.java:14: error: class, interface, or enum expected
    int sz=tree[x].size();
    ^
Main.java:15: error: class, interface, or enum expected
    for(int i=0;i
*/
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
vector<int> tree[40005];
int num[40005];
ll jc[40005],ny[40005];
const ll mod=1000000007;
bool vis[40005];
int dfs(int x){
    int cnt=0;
    int sz=tree[x].size();
    for(int i=0;i<sz;i++)cnt+=dfs(tree[x][i]);
    vis[x]=true;
    num[x]=cnt+1;
    return num[x];
}
ll exgcd(ll a,ll b,ll &x,ll &y){
    if(a==0&&b==0)return -1;
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
ll inv(ll a,ll n){
    ll x,y;
    ll d=exgcd(a,n,x,y);
    if(d==1)return (x%n+n)%n;
    else return -1;
}
int main(){
    jc[0]=jc[1]=ny[1]=1;
    for(int i=2;i<40003;i++)jc[i]=jc[i-1]*i%mod,ny[i]=inv(i,mod);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)tree[i].clear();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            tree[b].push_back(a);
        }
        for(int i=1;i<=n;i++)if(!vis[i])dfs(i);
        ll ans=jc[n];
        for(int i=1;i<=n;i++)ans=ans*ny[num[i]]%mod;
        printf("%lld\n",ans);
    }
    return 0;
}

