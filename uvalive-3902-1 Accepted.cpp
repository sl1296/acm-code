
#include<bits/stdc++.h>
using namespace std;
vector<int> node[1010],dn[1010];
int fa[1010];
int k;
bool is[1010];
void dfs(int n,int f,int d){
    fa[n]=f;
    if(node[n].size()==1 && d>k){
        dn[d].push_back(n);
        return;
    }
    for(int i=0;i<node[n].size();i++)if(node[n][i]!=f)dfs(node[n][i],n,d+1);
}
void dfs2(int n,int f,int d){
    is[n]=true;
    if(d<k)for(int i=0;i<node[n].size();i++)if(node[n][i]!=f)dfs2(node[n][i],n,d+1);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,s;
        int ans=0;
        scanf("%d%d%d",&n,&s,&k);
        for(int i=1;i<=n;i++){
            node[i].clear();
            dn[i].clear();
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            node[x].push_back(y);
            node[y].push_back(x);
        }
        dfs(s,-1,0);
        memset(is,false,sizeof(is));
        for(int i=n-1;i>k;i--){
            for(int j=0;j<dn[i].size();j++){
                int now=dn[i][j];
                if(!is[now]){
                    for(int z=0;z<k;z++)now=fa[now];
                    ans++;
                    dfs2(now,-1,0);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

