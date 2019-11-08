
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
char pp[1010][1010];
char in[1010];
struct ee{
    int next,to;
};
ee edge[1010];
int head[1010];
int ec;
int dfn[1010],low[1010];
int cnt,sp,id;
int stak[1010];
bool instak[1010];
int kuai[1010][1010];
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
    if(low[x]==dfn[x]){
        int tmp;
        kuai[cnt][0]=0;
        do{
            tmp=stak[--sp];
            kuai[cnt][++kuai[cnt][0]]=tmp;
            instak[tmp]=false;
        }while(tmp!=x);
        cnt++;
    }
}
int main(){
    int n,m,cas=1;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        memset(head,-1,sizeof(head));
        ec=0;
        n=0;
        map<string,int> ma;
        for(int i=0;i<m;i++){
            scanf("%s",in);
            int u=ma[in];
            if(u==0){
                strcpy(pp[++n],in);
                ma[in]=n;
                u=n;
            }
            scanf("%s",in);
            int v=ma[in];
            if(v==0){
                strcpy(pp[++n],in);
                ma[in]=n;
                v=n;
            }
            edge[ec]=(ee){head[u],v};
            head[u]=ec++;
        }
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instak,false,sizeof(instak));
        cnt=sp=id=0;
        for(int i=1;i<=n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        printf("Calling circles for data set %d:\n",cas++);
        for(int i=0;i<cnt;i++){
            for(int j=1;j<=kuai[i][0];j++){
                if(j>1)printf(", ");
                printf("%s",pp[kuai[i][j]]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

