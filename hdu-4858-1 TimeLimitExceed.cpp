
#include<cstdio>
#include<cstring>
int ss[200100],ee[200100],pre[200100],start[100100],val[100100],cnt;
void addedge(int from,int to){
    ss[cnt]=from;ee[cnt]=to;
    pre[cnt]=start[from];
    start[from]=cnt++;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        cnt=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)val[i]=0,start[i]=-1;
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int cmd;
            scanf("%d",&cmd);
            if(cmd){
                int u;
                scanf("%d",&u);
                long long ans=0;
                for(int i=start[u];i!=-1;i=pre[i])ans+=val[ee[i]];
                printf("%lld\n",ans);
            }else{
                int u,v;
                scanf("%d%d",&u,&v);
                val[u]+=v;
            }
        }
    }
    return 0;
}

