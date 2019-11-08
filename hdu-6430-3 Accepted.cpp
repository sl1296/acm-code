
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> vec[maxn];
vector<int> g[maxn];
void init(){
    int maxx=0;
    for(int i=1;i<=100000;i++){
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                vec[i].push_back(j);
                if(j*j!=i) vec[i].push_back(i/j);
            }
        }
    }
}
set<int> st[maxn];
set<int>::iterator it;
int dr[maxn],v[maxn],ans[maxn];
void dfs(int root){
    if(g[root].size()==0){
        dr[root]=root;
        for(int i=0;i<vec[v[root]].size();i++)
            st[root].insert(vec[v[root]][i]);
        ans[root]=-1;
    }else{
        for(int i=0;i<g[root].size();i++){
            int u=g[root][i];
            dfs(u);
            if(st[dr[root]].size()<st[dr[u]].size()) dr[root]=dr[u];
        }
        for(int i=0;i<vec[v[root]].size();i++){
            if(st[dr[root]].count(vec[v[root]][i]))
                ans[root]=max(ans[root],vec[v[root]][i]);
            else st[dr[root]].insert(vec[v[root]][i]);
        }
        for(int i=0;i<g[root].size();i++){
            int u=g[root][i];
            if(dr[root]==dr[u]) continue;
            for(it=st[dr[u]].begin();it!=st[dr[u]].end();it++){
                if(st[dr[root]].count(*it))
                    ans[root]=max(ans[root],*it);
                else st[dr[root]].insert(*it);
            }
        }
    }
}
int main(){
    init();
    int n,u;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&u);
        g[u].push_back(i);
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    dfs(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",ans[i]);
    return 0;
}


