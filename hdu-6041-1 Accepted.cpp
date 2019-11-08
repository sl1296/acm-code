
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct node{
    int f,t,v;
};
struct rec{
    int id;
    unsigned v;
    bool operator < (const rec &p) const{
        return v<p.v;
    }
};
int n,m,k;
vector<node> G[1010];
vector<unsigned> cir[1010];
int cnt,wayp,cirn;
int dfn[1010];
node way[1010];
unsigned ans[2][100010];
void dfs(int x,int f){
    dfn[x]=++cnt;
    int sz=G[x].size();
    for(int i=0;i<sz;i++){
        node ne=G[x][i];
        if(ne.t==f)continue;
        if(dfn[ne.t]==0){
            way[wayp++]=ne;
            dfs(ne.t,x);
            wayp--;
        }else if(dfn[ne.t]<dfn[x]){
            cir[++cirn].clear();
            cir[cirn].push_back(ne.v);
            int tmp=wayp;
            do{
                cir[cirn].push_back(way[--tmp].v);
            }while(way[tmp].f!=ne.t);
        }
    }
}
int main(){
    int cas=1;
    while(~scanf("%d%d",&n,&m)){
        unsigned all=0;
        for(int i=1;i<=n;i++)G[i].clear();
        for(int i=0;i<m;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            all+=z;
            G[x].push_back((node){x,y,z});
            G[y].push_back((node){y,x,z});
        }
        scanf("%d",&k);
        cnt=wayp=cirn=0;
        memset(dfn,0,sizeof(dfn));
        dfs(1,0);
        int siz[2]={1,0};
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=cirn;i++){
            int pre=(i-1)&1;
            int now=i&1;
            priority_queue<rec> qu;
            int sz=cir[i].size();
            for(int j=0;j<sz;j++){
                qu.push((rec){1,cir[i][j]+ans[pre][0]});
            }
            siz[now]=0;
            for(int i=0;i<k;i++){
                rec tmp=qu.top();
                qu.pop();
                ans[now][siz[now]++]=tmp.v;
                if(tmp.id<siz[pre]){
                    tmp.v=tmp.v-ans[pre][tmp.id-1]+ans[pre][tmp.id];
                    tmp.id++;
                    qu.push(tmp);
                }
                if(qu.empty())break;
            }
        }
        int nnow=cirn&1;
        int en=siz[nnow];
        unsigned re=0;
        for(int i=0;i<en;i++){
            re+=(unsigned)(i+1)*(all-ans[nnow][i]);
        }
        printf("Case #%d: %u\n",cas++,re);
    }
    return 0;
}

