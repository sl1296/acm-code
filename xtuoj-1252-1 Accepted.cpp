
#include<iostream>
#include<vector>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 100005 ;
int n ;
int tower[maxn] ;
bool f[maxn] ;
//struct Edge{
//    int from,to ;
//};
//vector<Edge> edges ;
struct node{
    int id;
    int x ;
    bool operator < (const node & p) const {
        return x<p.x ;
    }
};
vector<int>G[maxn] ;
void addEdge(int from,int to){
    //edges.push_back((Edge){from,to}) ;
    //int mm = edges.size() ;
    G[from].push_back(to);
}
int main(){
    while(~scanf("%d",&n)){
        priority_queue<node> qq ;
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            scanf("%d",&tower[i]) ;
            //int a ;
            //scanf("%d",&a) ;
            qq.push((node){i,tower[i]}) ;
        }
        for(int i=0;i<n-1;i++){
            int a,b ;
            scanf("%d%d",&a,&b) ;
            a--;
            b--;
            addEdge(a,b);
            addEdge(b,a);
        }
        int cnt=0;
        int ans = 0;
        memset(f,false,sizeof(f)) ;
        while(cnt!=n){
            cnt++ ;
            node top = qq.top() ;
            qq.pop() ;
            //printf("id = %d %d\n",top.id,top.x) ;
            int s = G[top.id].size() ;
            f[top.id] = true ;
            for(int i=0;i<s;i++){
                //printf("i=%d  xxx = %d\n",i,G[top.id][i]);
                ans+=(f[G[top.id][i]]?0:tower[G[top.id][i]]);
            }
        }
        printf("%d\n",ans) ;
    }
    return 0;
}


