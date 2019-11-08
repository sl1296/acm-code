
#include<bits/stdc++.h>
using namespace std;
vector<int> ve[1000010];
vector<int> vx[1000010];
long long ans=0;
int dfs(int x,int f){
    int sz=ve[x].size();
    int re=1;
    for(int i=0;i<sz;i++){
        int ne=ve[x][i];
        if(ne==f)continue;
        long long de=dfs(ne,x);
        re+=de;
        ans+=de*vx[x][i];
    }
    return re;
}
int main(){
    int n,k;
    while(~scanf("%d%d",&n,&k)){
        ans=0;
        for(int i=0;i<=n;i++){ve[i].clear();vx[i].clear();}
        for(int i=1;i<n;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            ve[a].push_back(b);
            vx[a].push_back(c);
            ve[b].push_back(a);
            vx[b].push_back(c);
        }
        dfs(1,-1);
        printf("%lld\n",ans);
    }
    return 0;
}

