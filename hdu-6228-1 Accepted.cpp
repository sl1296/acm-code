
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,k,ans;
vector<int> g[maxn];
int dfs(int root,int fa){
    int cnt=1;
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        if(to==fa) continue;
        int nc=dfs(to,root);
        if(nc>=k&&n-nc>=k) ans++;
        cnt+=nc;
    }
    return cnt;
}
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca--){
        scanf("%d%d",&n,&k);
        ans=0;
        for(int i=0;i<=n;i++)
            g[i].clear();
        int u,v;
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}

