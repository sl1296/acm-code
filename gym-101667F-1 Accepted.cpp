
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
pp dfs(int n,int m){
    if(n==1) return make_pair(1,1);
    int area=n*n/4;
    if(m<=area){
        pp p=dfs(n/2,m);
        return make_pair(p.second,p.first);
    }else if(m<=2*area){
        pp p=dfs(n/2,m-area);
        return make_pair(p.first,n/2+p.second);
    }else if(m<=3*area){
        pp p=dfs(n/2,m-2*area);
        return make_pair(n/2+p.first,n/2+p.second);
    }else{
        pp p=dfs(n/2,m-3*area);
        return make_pair(n-p.second+1,n/2-p.first+1);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    pp ans=dfs(n,m);
    printf("%d %d\n",ans.first,ans.second);
    return 0;
}

