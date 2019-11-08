
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ee{
    int next,to;
};
int n;
ee edge[10010];
int ec;
int head[110];
int id,cnt;
int bh[110];
int dfn[110],low[110];
int stak[110],sp;
bool instak[110];
int in[110],out[110];
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
int solve(int &re){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(instak,false,sizeof(instak));
    id=cnt=sp=0;
    for(int i=1;i<=n;i++){
        if(dfn[i]==0){
            tarjan(i);
        }
    }
    re=1;
    if(cnt==1)return 0;
    for(int i=1;i<=n;i++){
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
    re=r1;
    return max(r1,r2);
}
int main(){
    while(~scanf("%d",&n)){
        ec=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++){
            int tmp;
            while(1){
                scanf("%d",&tmp);
                if(!tmp)break;
                edge[ec]=(ee){head[i],tmp};
                head[i]=ec++;
                in[tmp]++;
            }
        }
        int ans1,ans2=solve(ans1);
        printf("%d\n%d\n",ans1,ans2);
    }
    return 0;
}

