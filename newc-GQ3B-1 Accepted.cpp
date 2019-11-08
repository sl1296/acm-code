
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 1000010
const ll mod=1e9+7;
vector<vector<int> > g;
ll d[maxn],dfa[maxn];
int fa[maxn];
vector<vector<ll> > vl,vr;
ll dfs1(int root){
    ll ans=1;
    int son=0;
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        if(to==fa[root]) continue;
        fa[to]=root;
        ans=ans*(dfs1(to)+1)%mod;
        vl[root].push_back((d[to]+1)%mod);
        vr[root].push_back((d[to]+1)%mod);
        ++son;
    }
    for(int i=1;i<son;++i)
        vl[root][i]=vl[root][i]*vl[root][i-1]%mod;
    for(int i=son-2;i>=0;--i)
        vr[root][i]=vr[root][i]*vr[root][i+1]%mod;
    return d[root]=ans;
}
ll get_l(int x,int k)
{
    if(vl[x].size()==0) return 1;
    if(k==0) return 1;
    return vl[x][k-1];
}
ll get_r(int x,int k)
{
    if(vr[x].size()==0) return 1;
    if(k==vr[x].size()-1) return 1;
    return vr[x][k+1];
}
void dfs2(int root,int k){
    if(root!=1) d[root]=(d[root]+d[root]*dfa[fa[root]]%mod*get_l(fa[root],k)%mod*get_r(fa[root],k)%mod)%mod;
    int son=0;
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        if(to==fa[root]) continue;
        dfs2(to,son++);
    }
}
void dfs3(int root)
{
    int cnt=0;
    for(auto y:g[root])
    {
        if(y==fa[root]) continue;
        dfa[y]=(dfa[root]*get_l(root,cnt)%mod*get_r(root,cnt)%mod+1)%mod;
        dfs3(y);
        ++cnt;
    }
}
int main(){
    int n,u,v;
    while(scanf("%d",&n)!=EOF){
        g.clear();vl.clear();vr.clear();
        for(int i=0;i<=n;i++){
            g.push_back(vector<int>());
            vl.push_back(vector<ll>());
            vr.push_back(vector<ll>());
            d[i]=fa[i]=0;
        }
        g[0].push_back(1);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs1(0);
        dfa[1]=1;
        dfs3(1);
        dfs2(1,0);
        for(int i=1;i<=n;i++)
            printf("%lld\n",d[i]);
    }
    return 0;
}
/*
6
1 2
1 3
2 4
4 5
4 6
 
12
15
7
16
9
9
*/

