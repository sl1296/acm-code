
#include<cstdio>
#include<vector>
using namespace std;
vector<int> ve[1000010];
int ma[1000010],mb[1000010],ans;
void dfs(int x,int f){
    int sz=ve[x].size();
    for(int i=0;i<sz;++i){
        int nxt=ve[x][i];
        if(nxt==f)continue;
        dfs(nxt,x);
        if(ma[nxt]+1>ma[x]){
            ma[x]=ma[nxt]+1;
        }else if(ma[nxt]+1>mb[x]){
            mb[x]=ma[nxt]+1;
        }
    }
    ans=max(ans,ma[x]+mb[x]+1);
}
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d",&a,&b);
        ve[a].push_back(b);
        ve[b].push_back(a);
    }
    dfs(1,-1);
    printf("%d\n",ans);
}

