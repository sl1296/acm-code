
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ee{
    int next,to;
};
ee edge[10010];
int head[110],ec;
int dfn[110],low[110];
int stak[110],sp;
bool instak[110];
int bh[110];
int cnt,id;
int in[110],out[110];
void tarjan(int x){
    dfn[x]=low[x]=++id;
    instak[x]=true;
    stak[sp++]=x;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int ne=edge[i].to;
        if(!dfn[ne]){
            tarjan(ne);
            low[x]=min(low[x],low[ne]);
        }else{
            if(instak[ne])low[x]=min(low[x],dfn[ne]);
        }
    }
    if(low[x]==dfn[x]){
        int tmp;
        do{
            tmp=stak[--sp];
            instak[tmp]=false;
            bh[tmp]=cnt;
        }while(tmp!=x);
        cnt++;
    }
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        memset(head,-1,sizeof(head));
        ec=0;
        for(int i=1;i<=n;i++){
            int a;
            while(1){
                scanf("%d",&a);
                if(a==0)break;
                edge[ec]=(ee){head[i],a};
                head[i]=ec++;
            }
        }
        memset(dfn,0,sizeof(dfn));
        memset(instak,false,sizeof(instak));
        cnt=sp=id=0;
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        if(cnt==1){
            printf("1\n0\n");
            continue;
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++){
            for(int j=head[i];j!=-1;j=edge[j].next){
                int ne=edge[j].to;
                if(bh[i]!=bh[ne]){
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
        printf("%d\n%d\n",r1,max(r1,r2));
    }
    return 0;
}

