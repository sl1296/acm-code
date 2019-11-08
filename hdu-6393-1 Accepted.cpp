
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100010
int size[maxn],dep[maxn],val[maxn],id[maxn],hson[maxn],top[maxn],fa[maxn];//定义
int num;
vector<int> g[maxn];
struct tree {
    int x,y,z;
} e[maxn]; //起点重点权值
struct SegTree{
    ll sumv[maxn*4];
    void build(int o,int L,int R){
        if(L==R){
            sumv[o]=val[L];
        }else{
            int M=(L+R)/2;
            build(o*2,L,M);build(o*2+1,M+1,R);
            sumv[o]=sumv[o*2]+sumv[o*2+1];
        }
    }
    void update(int o,int L,int R,int p,int v){
        if(L==R) sumv[o]=v;
        else{
            int M=(L+R)/2;
            if(p<=M) update(o*2,L,M,p,v);
            else update(o*2+1,M+1,R,p,v);
            sumv[o]=sumv[o*2]+sumv[o*2+1];
        }
    }
    ll query(int o,int L,int R,int qL,int qR){
//        printf("%d %d %d %d\n",L,R,qL,qR);
        if(qL<=L&&R<=qR) return sumv[o];
        int M=(L+R)/2;
        ll ans=0;
        if(qL<=M) ans+=query(o*2,L,M,qL,qR);
        if(qR>M) ans+=query(o*2+1,M+1,R,qL,qR);
        return ans;
    }
}T;
void dfs1(int d,int f,int u) { //d：深度 f:父节点 u：当前节点
    dep[u]=d;
    size[u]=1;
    hson[u]=0;
    fa[u]=f;
    for(vector<int>::iterator it=g[u].begin(); it!=g[u].end(); it++) {
        if(*it==f) continue;
        dfs1(d+1,u,*it);
        size[u]+=size[*it];
        if(size[hson[u]]<size[*it])
            hson[u]=*it;//找重儿子
    }
}
void dfs2(int u,int tp) {
    top[u]=tp;//赋值top
    id[u]=num++;//赋值id
    if(hson[u]) dfs2(hson[u],tp);//优先重儿子
    for(vector<int>::iterator it=g[u].begin(); it!=g[u].end(); it++) {
        if(*it==fa[u]||*it==hson[u]) continue;
        dfs2(*it,*it);
    }
}
ll find(int u,int v,int n) {
//    printf("--%d %d %d\n",u,v,n);
    int t1=top[u],t2=top[v];
    ll ans=0;
    while(t1!=t2) {

        if(dep[t1]<dep[t2]) {
            swap(t1,t2);
            swap(u,v);
        }
        ans+=T.query(1,2,n,id[t1],id[u]);
        u=fa[t1];
        t1=top[u];
    }
    if(u==v) return ans;
    if (dep[u] > dep[v]) swap(u, v);
//    printf("---%d %d %d %d\n",u,v,id[hson[u]],id[v]);
    ans+=T.query(1,2,n,id[hson[u]], id[v]);
    return ans;
}
void init(int n) {
    dfs1(1,0,1);
    dfs2(1,1);
    for(int i=1; i<n; i++) {
        if(dep[e[i].x]<dep[e[i].y])
            swap(e[i].x, e[i].y);
        val[id[e[i].x]] = e[i].z;
    }
    T.build(1,2,n);
}
int father[maxn];
int findfa(int x){
    if(father[x]==x) return x;
    return father[x]=findfa(father[x]);
}
int main() {
    int ca;
    scanf("%d",&ca);
    while(ca--) {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=0;i<=n+1;i++){
            g[i].clear();
            father[i]=i;
        }
        num=1;
        int j=1,x,y,z,cu,cv,cc,cid;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&z);
            if(findfa(x)==findfa(y)){
                cu=x;cv=y;cc=z;cid=i;
            }else{
                father[findfa(x)]=findfa(y);
                g[x].push_back(y);
                g[y].push_back(x);
                e[j].x=x;
                e[j].y=y;
                e[j++].z=z;
            }
        }
        init(n);
        int op,a,b;
        while(q--){
            scanf("%d%d%d",&op,&a,&b);
            if(op==0){
                if(a==cid) cc=b;
                else if(a>cid) T.update(1,2,n,id[e[a-1].x],b);
                else T.update(1,2,n,id[e[a].x],b);
            }else{
                ll ans=find(a,b,n);
                ans=min(ans,find(a,cu,n)+find(cv,b,n)+cc);
                ans=min(ans,find(a,cv,n)+find(cu,b,n)+cc);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}

