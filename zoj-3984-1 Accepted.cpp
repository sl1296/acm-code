
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int du[maxn];
struct SegTree{
    int maxv[maxn*4];
    void build(int o,int L,int R){
        if(L==R) maxv[o]=du[L];
        else{
            int M=(L+R)/2;
            build(o*2,L,M);
            build(o*2+1,M+1,R);
            maxv[o]=max(maxv[o*2],maxv[o*2+1]);
        }
    }
    void update(int o,int L,int R,int p,int v){
        if(L==R) maxv[o]-=v;
        else{
            int M=(L+R)/2;
            if(p<=M) update(o*2,L,M,p,v);
            else update(o*2+1,M+1,R,p,v);
            maxv[o]=max(maxv[o*2],maxv[o*2+1]);
        }
    }
    int query(int o,int L,int R){
        if(L==R) return L;
        int M=(L+R)/2;
        if(maxv[o*2]>maxv[o*2+1]) return query(o*2,L,M);
        else return query(o*2+1,M+1,R);
    }
}T;
vector<int> g[maxn];
int f[maxn];
vector<int> vec;
bool used[maxn];
bool vis[maxn];
int dfs(int root){
    vec.push_back(root);
    vis[root]=true;
    int ans=1;
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        if(!vis[to]&&!used[to]) ans+=dfs(to);
    }
    return ans;
}
int fa[maxn];
int findfa(int x){
    return x==fa[x]?x:fa[x]=findfa(fa[x]);
}
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        int n,m,u,v;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            g[i].clear();
            du[i]=0;
            fa[i]=i;
            vis[i]=used[i]=false;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
            du[u]++;
            du[v]++;
        }
        T.build(1,1,n);
        bool flag=true;
        for(int ts=1;ts<=n;ts++){
            int p=T.query(1,1,n);
            vec.clear();
            int s1=dfs(p),s2=1;
            for(int i=0;i<g[p].size();i++)
                if(!used[g[p][i]]) s2++;
            if(s1!=s2){
                flag=false;
                break;
            }else{
                for(int i=0;i<vec.size();i++){
                    T.update(1,1,n,vec[i],1);
                    vis[vec[i]]=false;
                }
                T.update(1,1,n,p,T.maxv[1]+1);
                used[p]=true;
                f[ts]=p;
            }
        }
        if(flag){
            printf("Yes\n");
            for(int ts=n;ts;ts--){
                vec.clear();
                int p=f[ts];
                for(int i=0;i<g[p].size();i++){
                    int to=g[p][i];
                    if(used[to]||to!=fa[to]) continue;
                    vec.push_back(to);
                }
                printf("%d %d",p,vec.size());
                if(vec.size()==0) printf("\n");
                else printf(" ");
                for(int i=0;i<vec.size();i++){
                    printf("%d%c",vec[i],i==vec.size()-1?'\n':' ');
                    fa[findfa(vec[i])]=findfa(p);
                }
                used[p]=false;
            }
        }else printf("No\n");
    }
    return 0;
}
/*
10
6 9
1 2
2 6
6 1
1 3
3 4
3 5
1 4
4 5
5 1
*/

