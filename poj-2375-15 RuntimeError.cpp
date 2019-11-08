
#include<cstdio>
#include<cstring>
#include<algorithm>
#pragma comment(linker,"/STACk:10240000,10240000")
using namespace std;
int mapp[1010][1010];
int addx[6]={0,0,1,-1};
int addy[6]={1,-1,0,0};
int point[1010][1010];
struct ee{
    int next,to;
};
ee edge[2000010];
int head[2000010],ec;
int dfn[2000010],low[2000010];
int stak[2000010],sp;
bool instak[2000010];
int id,cnt;
int bh[2000010];
int in[2000010],out[2000010];
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
int main(){
    int y,x;
    while(~scanf("%d%d",&y,&x)){
        int cc=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                scanf("%d",&mapp[i][j]);
                point[i][j]=cc++;
            }
        }
        ec=0;
        memset(head,-1,sizeof(head));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=0;k<4;k++){
                    int ni=i+addx[k];
                    int nj=j+addy[k];
                    if(ni<1||nj<1||ni>x||nj>y)continue;
                    if(mapp[i][j]<mapp[ni][nj])continue;
                    int from=point[i][j];
                    int to=point[ni][nj];
                    edge[ec]=(ee){head[from],to};
                    head[from]=ec++;
                }
            }
        }
        memset(dfn,0,sizeof(dfn));
        memset(instak,false,sizeof(instak));
        sp=cnt=id=0;
        for(int i=1;i<cc;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        if(cnt==1){
            printf("0\n");
            continue;
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<cc;i++){
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
        printf("%d\n",max(r1,r2));
    }
    return 0;
}

