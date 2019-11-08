
#include<bits/stdc++.h>
using namespace std;
#define maxn 150005
struct Edge{
    int to,w,nxt;
}e[maxn*2];
int head[maxn],edgelen;
void insertedge(int u,int v,int w){
    ++edgelen;e[edgelen].to=v;e[edgelen].w=w;e[edgelen].nxt=head[u];head[u]=edgelen;
    ++edgelen;e[edgelen].to=u;e[edgelen].w=w;e[edgelen].nxt=head[v];head[v]=edgelen;
}
struct node{
    int u,v,w;
    bool operator <(const node &rhs)const{
        return w<rhs.w;
    }
}edge[maxn];
int sz[maxn],fa[maxn];
int findfa(int x){
    return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
int ans[maxn],T[maxn],Xor[maxn];
int ch[maxn*30][2],tot;
int getmax(int u,int v,int k){
    if(k<0) return 0;
    int ans=0;
    if(ch[u][0]&&ch[v][1]){
        ans=(1<<k)|getmax(ch[u][0],ch[v][1],k-1);
    }
    if(ch[u][1]&&ch[v][0]){
        ans=max(ans,(1<<k)|getmax(ch[u][1],ch[v][0],k-1));
    }
    if(ans) return ans;
    if(ch[u][0]&&ch[v][0]) ans=getmax(ch[u][0],ch[v][0],k-1);
    if(ch[u][1]&&ch[v][1]) ans=max(ans,getmax(ch[u][1],ch[v][1],k-1));
    return ans;
}
void insertTree(int u,int v,int k){
    if(k<0) return;
    if(ch[u][0]&&ch[v][0]) insertTree(ch[u][0],ch[v][0],k-1);
    if(ch[u][1]&&ch[v][1]) insertTree(ch[u][1],ch[v][1],k-1);
    if(!ch[u][0]) ch[u][0]=ch[v][0];
    if(!ch[u][1]) ch[u][1]=ch[v][1];
}
void insert(int u,int x){
    for(int i=18;i>=0;i--){
        int to=(x>>i&1);
        if(!ch[u][to]){
            ch[u][to]=++tot;
            ch[tot][0]=ch[tot][1]=0;
        }
        u=ch[u][to];
    }
}
void dfs(int root,int f,int z){
    T[root]=++tot;
    insert(T[root],z);
    for(int i=head[root];i;i=e[i].nxt){
        int to=e[i].to;
        Xor[to]=Xor[root]^e[i].w;
        if(to!=f) dfs(to,root,z^e[i].w);
    }
}
int main(){
    int n;
//    freopen("data.txt","r",stdin);
//    freopen("ans.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        fa[i]=i;
        sz[i]=1;
    }
    n--;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        insertedge(edge[i].u,edge[i].v,edge[i].w);
    }
    dfs(1,0,0);
    sort(edge,edge+n);
    for(int i=0;i<n;i++){
        int u=findfa(edge[i].u),v=findfa(edge[i].v),w=edge[i].w;
        if(sz[u]>sz[v]) swap(u,v);
        ans[w]=getmax(T[v],T[u],18);
        insertTree(T[v],T[u],18);
        fa[u]=v;sz[v]+=sz[u];
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}
/*
4
1 2 1
2 3 2
1 4 3
*/

