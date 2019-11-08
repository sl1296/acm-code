
#include<cstdio>
#include<cstring>
#include<map>
using namespace std;
struct node{
    int s,e;
    bool operator < (const node &p) const{
        if(s!=p.s)return s<p.s;return e<p.e;
    }
};
map<node,int> ma;
int ss[200100],ee[200100],pre[200100],num[200100],start[100100],val[100100],cnt;
void addedge(int from,int to){
    int dd=ma[(node){from,to}];
    if(dd){
        num[dd]++;
        return;
    }
    ma[(node){from,to}]=cnt;
    ss[cnt]=from;ee[cnt]=to;
    pre[cnt]=start[from];
    num[cnt]=1;
    start[from]=cnt++;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        ma.clear();
        cnt=1;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)val[i]=0,start[i]=-1;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int cmd;
            scanf("%d",&cmd);
            if(cmd){
                int u;
                scanf("%d",&u);
                long long ans=0;
                for(int i=start[u];i!=-1;i=pre[i])ans+=val[ee[i]]*num[i];
                printf("%lld\n",ans);
            }else{
                int u,v;
                scanf("%d%d",&u,&v);
                val[u]+=v;
            }
        }
    }
    return 0;
}

