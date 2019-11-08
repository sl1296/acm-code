
#include<cstdio>
#include<vector>
using namespace std;
vector<int> ve[1000010];
int ma[1000010],mb[1000010],ans;
int c[1000010],a[1000010],b[1000010];
void dfs(int x,int f){
    int sz=ve[x].size();
    for(int i=0;i<sz;++i){
        int nxt=ve[x][i];
        if(nxt==f)continue;
        dfs(nxt,x);
        if(ma[nxt]+1>ma[x]){
            mb[x]=ma[x];
            ma[x]=ma[nxt]+1;
        }else if(ma[nxt]+1>mb[x]){
            mb[x]=ma[nxt]+1;
        }
    }
    ans=max(ans,ma[x]+mb[x]+1);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a[i],&b[i]);
        ++c[a[i]];
        ++c[b[i]];
    }
    for(int i=1;i<=n;++i)ve[i].resize(c[i]);
    for(int i=1;i<n;++i){
        ve[a[i]][--c[a[i]]]=b[i];
        ve[b[i]][--c[b[i]]]=a[i];
    }
    dfs(1,-1);
    printf("%d\n",ans);
}

