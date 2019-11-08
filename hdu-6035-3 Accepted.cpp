
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c[200010];
int sz[200010];
int sum[200010];
bool use[200010];
ll ans;
vector<int> ve[200010];
int dfs(int x,int f){
    sz[x]=1;
    int allson=0;
    int vsz=ve[x].size();
    for(int i=0;i<vsz;i++){
        int nex=ve[x][i];
        if(nex==f)continue;
        int last=sum[c[x]];
        sz[x]+=dfs(nex,x);
        ll add=sum[c[x]]-last;
        ans=ans+(sz[nex]-add)*(sz[nex]-add-1)/2;
        allson+=sz[nex]-add;
    }
    sum[c[x]]+=allson+1;
    return sz[x];
}
int main(){
    int n;
    int cas=1;
    while(~scanf("%d",&n)){
        int cnt=0;
        memset(sum,0,sizeof(sum));
        memset(sz,0,sizeof(sz));
        memset(use,false,sizeof(use));
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
            if(!use[c[i]]){
                use[c[i]]=true;
                cnt++;
            }
            ve[i].clear();
        }
        for(int i=1;i<n;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            ve[a].push_back(b);
            ve[b].push_back(a);
        }
        ans=0;
        dfs(1,-1);
        for(int i=1;i<=n;i++){
            if(use[i]){
                ans+=1LL*(n-sum[i])*(n-sum[i]-1)/2;
            }
        }
        printf("Case #%d: %lld\n",cas++,1LL*n*(n-1)/2*cnt-ans);
    }
    return 0;
}

