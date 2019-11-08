
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[510][510];
int tx[4]={0,0,1,-1};
int ty[4]={1,-1,0,0};
struct ee{
    int next,to;
};
const int maxn=1500010;
ee edge[maxn];
int head[maxn],ec,N;
int dfn[maxn],low[maxn],id;
int stak[maxn],sp;
bool instak[maxn];
int bh[maxn],cnt;
int in[maxn],out[maxn];
void tarjan(int x){
    dfn[x]=low[x]=++id;
    stak[sp++]=x;
    instak[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int ne=edge[i].to;
        if(!dfn[ne]){
            tarjan(ne);
            low[x]=min(low[x],low[ne]);
        }else{
            if(instak[ne])low[x]=min(low[x],dfn[ne]);
        }
    }
    if(dfn[x]==low[x]){
        int tmp;
        do{
            tmp=stak[--sp];
            instak[tmp]=false;
            bh[tmp]=cnt;
        }while(tmp!=x);
        cnt++;
    }
}
int solve(){
    memset(dfn,0,sizeof(dfn));
    memset(instak,false,sizeof(instak));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    cnt=id=sp=0;
    for(int i=0;i<N;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    if(cnt==1)return 0;
    for(int i=0;i<N;i++){
        for(int j=head[i];j!=-1;j=edge[j].next){
            int ne=edge[j].to;
            if(bh[ne]!=bh[i]){
                out[bh[i]]++;
                in[bh[ne]]++;
            }
        }
    }
    int r1=0,r2=0;
    for(int i=0;i<cnt;i++){
        if(!in[i])r1++;
        if(!out[i])r2++;
    }
    return max(r1,r2);
}
int main(){
    int y,x;
    while(~scanf("%d%d",&y,&x)){
        memset(head,-1,sizeof(head));
        ec=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                scanf("%d",&a[i][j]);
            }
        }
        N=x*y;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                int from=i*y+j;
                for(int k=0;k<4;k++){
                    int nx=i+tx[k],ny=j+ty[k];
                    int to=nx*y+ny;
                    if(nx<0||ny<0||nx>=x||ny>=y||a[nx][ny]>a[i][j])continue;
                    edge[ec]=(ee){head[from],to};
                    head[from]=ec++;
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}

