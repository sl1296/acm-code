
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ee{
    int next,to;
};
int mapp[510][510];
int id[510][510];
ee edge1[1000010],edge2[1000010];
int ec1,ec2;
int head1[250010],head2[250010];
bool vis1[250010],vis2[250010];
int stak[250010],sp;
int bh[250010];
int tx[6]={0,0,1,-1};
int ty[6]={1,-1,0,0};
int in[250010],out[250010];
void dfs1(int x){
    vis1[x]=true;
    for(int i=head1[x];i!=-1;i=edge1[i].next){
        int ne=edge1[i].to;
        if(!vis1[ne])dfs1(ne);
    }
    stak[sp++]=x;
}
void dfs2(int x,int v){
    vis2[x]=true;
    bh[x]=v;
    for(int i=head2[x];i!=-1;i=edge2[i].next){
        int ne=edge2[i].to;
        if(!vis2[ne])dfs2(ne,v);
    }
}
int main(){
    int y,x;
    while(~scanf("%d%d",&y,&x)){
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        int cc=1;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                scanf("%d",&mapp[i][j]);
                id[i][j]=cc++;
            }
        }
        ec1=ec2=sp=0;
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                for(int k=0;k<4;k++){
                    int ni=i+tx[k],nj=j+ty[k];
                    if(ni<1||nj<1||ni>x||nj>y)continue;
                    if(mapp[ni][nj]>mapp[i][j])continue;
                    int from=id[i][j],to=id[ni][nj];
                    edge1[ec1]=(ee){head1[from],to};
                    head1[from]=ec1++;
                    edge2[ec2]=(ee){head2[to],from};
                    head2[to]=ec2++;
                }
            }
        }
        memset(vis1,false,sizeof(vis1));
        memset(vis2,false,sizeof(vis2));
        for(int i=1;i<cc;i++){
            if(!vis1[i]){
                dfs1(i);
            }
        }
        int cnt=0;
        while(sp){
            int tmp=stak[--sp];
            if(!vis2[tmp]){
                dfs2(tmp,cnt);
                cnt++;
            }
        }
        if(cnt==1){
            printf("0\n");
            continue;
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<cc;i++){
            for(int j=head1[i];j!=-1;j=edge1[j].next){
                int ne=edge1[j].to;
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

