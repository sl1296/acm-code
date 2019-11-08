
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ee{
    int next,to;
};
int head[20010];
ee edge[50010];
int ecc;
int n,m;
int stak[20010],sp;
bool instak[20010];
int dfn[20010],low[20010],id;
int bh[20010],cnt;
int in[20010],out[20010];
void tarjan(int x){
    dfn[x]=low[x]=++id;
    stak[sp++]=x;
    instak[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int ne=edge[i].to;
        if(dfn[ne]){
            if(instak[ne])low[x]=min(low[x],dfn[ne]);
        }else{
            tarjan(ne);
            low[x]=min(low[x],low[ne]);
        }
    }
    if(low[x]==dfn[x]){
        int tmp;
        do{
            tmp=stak[--sp];
            bh[tmp]=cnt;
            instak[tmp]=false;
        }while(tmp!=x);
        cnt++;
    }
}
int solve(){
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(instak,false,sizeof(instak));
    id=cnt=sp=0;
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    if(cnt==1)return 0;
    int ret=0;
    for(int i=1;i<=n;i++){
        for(int j=head[i];j!=-1;j=edge[j].next){
            int t1=bh[i];
            int t2=bh[edge[j].to];
            if(t1!=t2){
                out[t1]++;
                in[t2]++;
            }
        }
    }
    int c1=0,c2=0;
    for(int i=0;i<cnt;i++){
        if(in[i]==0)c1++;
        if(out[i]==0)c2++;
    }
    return max(c1,c2);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        ecc=0;
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            edge[ecc]=(ee){head[u],v};
            head[u]=ecc++;
        }
        printf("%d\n",solve());
    }
    return 0;
}

