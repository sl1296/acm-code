
#include <vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
#define maxn 200010
#define inf 0x3f3f3f3f
struct Edge {
    int to, cost;
    Edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
struct node{
    ll sum;
    int u,k;
    node() {}
    node(ll sum,int u,int k):sum(sum),u(u),k(k) {}
    bool operator <(const node &rhs)const{
        return sum>rhs.sum;
    }
};
vector<Edge> G[maxn/2];
int n,m,k;
ll d[maxn/2][11];
priority_queue<node> que;
ll dijkstra(int s) {
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++) d[i][j]=1e18;
    }
    while(!que.empty()) que.pop();
    d[s][0] = 0;

    que.push(node(0,s,0));
    ll ans=1e18;
    while (!que.empty()) {
        node p = que.top();
        que.pop();
        int v = p.u;
        if(v==n) ans=min(ans,d[v][p.k]);
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = G[v][i];
            if (d[v][p.k] + e.cost < d[e.to][p.k]) {
                d[e.to][p.k] = d[v][p.k] + e.cost;
                que.push(node(d[e.to][p.k], e.to ,p.k));
            }
            if(p.k<k&&d[v][p.k]<d[e.to][p.k+1]){
                d[e.to][p.k+1] = d[v][p.k];
                que.push(node(d[e.to][p.k+1], e.to ,p.k+1));
            }
        }
    }
    return ans;
}

int main() {
    int ca;
    scanf("%d",&ca);
    while(ca--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<=n+1;i++) G[i].clear();
        int u,v,c;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&c);
            G[u].push_back(Edge(v,c));
            G[v].push_back(Edge(u,c));
        }
        printf("%lld\n",dijkstra(1));
    }
    return 0;
}

