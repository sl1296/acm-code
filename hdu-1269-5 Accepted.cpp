
#include<cstdio>
#include<cstring>
struct ee{
    int next,to;
};
ee edge[100010],edge2[100010];
int ec,ec2;
int head[10010],head2[10010];
bool vis[10010],vis2[10010];
int stak[10010],sp;
void dfs1(int x){
    vis[x]=true;
    for(int i=head[x];i!=-1;i=edge[i].next){
        int ne=edge[i].to;
        if(!vis[ne])dfs1(ne);
    }
    stak[sp++]=x;
}
void dfs2(int x){
    vis2[x]=true;
    for(int i=head2[x];i!=-1;i=edge2[i].next){
        int ne=edge2[i].to;
        if(!vis2[ne])dfs2(ne);
    }
}
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)break;
        memset(head,-1,sizeof(head));
        memset(head2,-1,sizeof(head2));
        memset(vis,false,sizeof(vis));
        memset(vis2,false,sizeof(vis2));
        sp=ec=ec2=0;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            edge[ec]=(ee){head[a],b};
            head[a]=ec++;
            edge2[ec2]=(ee){head2[b],a};
            head2[b]=ec2++;
        }
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs1(i);
            }
        }
        int cnt=0;
        while(sp){
            int tmp=stak[--sp];
            if(!vis2[tmp]){
                dfs2(tmp);
                cnt++;
            }
        }
        if(cnt==1){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}

