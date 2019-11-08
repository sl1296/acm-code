
#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
vector<int> g[maxn];
int v[maxn];
int main(){
    int n,t;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        g[t].push_back(i);
    }
    int f=n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++)
            v[g[i][j]]=f--;
    }
    for(int i=0;i<n;i++)
        printf("%d%c",v[i],i==n-1?'\n':' ');
    return 0;
}

