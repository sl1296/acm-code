
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ee{
    int next,to;
};
ee edge1[50010],edge2[50010];
int head1[20010],head2[20010];
int ec1,ec2;
bool vis1[20010],vis2[20010];
int stak[20010],sp;
int bh[20010];
int in[20010],out[20010];
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
    int t;
    scanf("%d",&t);
    while(t--){
        memset(head1,-1,sizeof(head1));
        memset(head2,-1,sizeof(head2));
        ec1=ec2=sp=0;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            edge1[ec1]=(ee){head1[a],b};
            head1[a]=ec1++;
            edge2[ec2]=(ee){head2[b],a};
            head2[b]=ec2++;
        }
        memset(vis1,false,sizeof(vis1));
        memset(vis2,false,sizeof(vis2));
        for(int i=1;i<=n;i++){
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
        for(int i=1;i<=n;i++){
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

