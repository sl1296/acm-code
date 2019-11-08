
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
ee edge[1000010];
int head[250010],ec,N;
int dfn[250010],low[250010],id;
int stak[250010],sp;
bool instak[250010];
int bh[250010],cnt;
int in[250010],out[250010];
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
    memset(low,0,sizeof(low));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(instak,false,sizeof(instak));
    id=cnt=sp=0;
    for(int i=0;i<N;i++){
        if(dfn[i]==0){
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
        if(in[i]==0)r1++;
        if(out[i]==0)r2++;
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

