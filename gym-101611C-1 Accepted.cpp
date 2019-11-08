
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int h[maxn],f[maxn],fa[maxn];
void dfs(int root){
    h[root]=0;f[root]=1;
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        if(to==fa[root]) continue;
        fa[to]=root;
        dfs(to);
        if(f[to]+1>f[root]){
            f[root]=f[to]+1;
            h[root]=to;
        }
    }
}
vector<int> vec[21];
int x[maxn],y[maxn];
int main(){
    int n;
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    u=1;
    while(u){
        vec[0].push_back(u);
        u=h[u];
    }
    for(int i=0;i<20;i++){
        for(int j=0;j<vec[i].size();j++){
            u=vec[i][j];
            for(int k=0;k<g[u].size();k++){
                v=g[u][k];
                if(h[u]==v||fa[u]==v) continue;
                while(v){
                    vec[i+1].push_back(v);
                    v=h[v];
                }
            }
        }
    }
    for(int i=0;i<21;i++){
        for(int j=0;j<vec[i].size();j++){
            u=vec[i][j];
            x[u]=j+1;y[u]=i+1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d %d\n",x[i],y[i]);
    return 0;
}

