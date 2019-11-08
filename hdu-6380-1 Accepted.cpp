
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ve[200010];
bool vis[200010];
void dfs(int x,int fa){
    vis[x]=true;
    int sz=ve[x].size();
    for(int i=0;i<sz;i++){
        if(ve[x][i]!=fa){
            dfs(ve[x][i],x);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,false,sizeof(vis));
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1);
                cnt++;
            }
            ans=max(ans,(int)ve[i].size());
        }
        ans=min(ans+cnt-1+k,n-1);
        printf("%d\n",ans);
        for(int i=0;i<n;i++)ve[i].clear();
    }
}

