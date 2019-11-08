
#include<cstdio>
#include<cstring>
int head[55];
int d[55];
struct edge{
    int next,to;
};
edge ee[3010];
bool use[3010];
int fa[55];
int ffind(int x){
    if(fa[x]==x)return x;
    return fa[x]=ffind(fa[x]);
}
int cnt;
void dfs(int x){
    for(int i=head[x];i!=-1;i=ee[i].next){
        if(!use[i]){
            use[i]=true;
            use[i^1]=true;
            dfs(ee[i].to);
            printf("%d %d\n",ee[i].to,x);
        }
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        int n;
        scanf("%d",&n);
        cnt=0;
        memset(d,0,sizeof(d));
        memset(head,-1,sizeof(head));
        memset(use,false,sizeof(use));
        for(int i=0;i<55;i++)fa[i]=i;
        for(int i=0;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            d[u]++;d[v]++;
            ee[cnt]=(edge){head[u],v};
            head[u]=cnt++;
            ee[cnt]=(edge){head[v],u};
            head[v]=cnt++;
            fa[ffind(u)]=ffind(v);
        }
        bool ans=true;
        for(int i=0;i<55;i++){
            if(d[i]&&d[i]&1){
                ans=false;
                break;
            }
        }
        if(ans){
            bool st=false;
            int ff;
            for(int i=0;i<55;i++){
                if(d[i]){
                    if(!st){
                        st=true;
                        ff=ffind(i);
                    }else{
                        if(ff!=ffind(i))ans=false;
                        break;
                    }
                }
            }
        }
        if(z>1)printf("\n");
        printf("Case #%d\n",z);
        if(!ans){
            printf("some beads may be lost\n");
            continue;
        }
        for(int i=0;i<55;i++){
            if(d[i]){
                dfs(i);
            }
        }
    }
    return 0;
}

