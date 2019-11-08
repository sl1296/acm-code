
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 100010
vector<int> g[maxn];
vector<int> vec[maxn];
map<int,int> mp;
int T[maxn],K[maxn],a[maxn];
ll ans[maxn];
void dfs(int root,int pre){
    mp[a[root]]++;
    T[root]=T[pre];
    K[root]=T[pre];
    if(mp[a[root]]==1){
        T[root]++;
    }
//    printf("%d : %d %d\n",root,K[root],T[pre]);
    int s=1,sz=vec[a[root]].size();
    if(sz!=0) s=vec[a[root]][sz-1];
    ans[root]=ans[pre]+K[root]-K[s];
//    printf("---%d %d %d\n",root,ans[root],s);
    vec[a[root]].push_back(root);
    for(int i=0;i<g[root].size();i++){
        int to=g[root][i];
        dfs(to,root);
    }
    mp[a[root]]--;
    vec[a[root]].pop_back();
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int p;
        for(int i=0;i<=n;i++){
            g[i].clear();
            K[i]=T[i]=ans[i]=0;
            vec[i].clear();
        }
        for(int i=2;i<=n;i++){
            scanf("%d",&p);
            g[p].push_back(i);
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        mp.clear();
        dfs(1,0);
        for(int i=2;i<=n;i++)
            printf("%lld\n",ans[i]);
    }
    return 0;
}

