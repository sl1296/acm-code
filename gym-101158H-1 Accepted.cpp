
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int head[N],to[N*2],w[N*2],pre[N*2];
int dfn[N],low[N],sta[N],be[N],ru[N],dp1[N],dp2[N];
bool insta[N],vis[N];
int n,m,e,cnt,top;
bool has_circle;
vector<int> tree[N],g[N],block[N];
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
void dfs1(int x,int id)
{
    vis[x]=true;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        if(w[i]==id) continue;
        int y=to[i];
        if(insta[y]) has_circle=true;
        if(vis[y]) continue;
        insta[y]=true;
        dfs1(y,w[i]);
        insta[y]=false;
    }
}
void tarjan(int x)
{
    dfn[x]=low[x]=++cnt;
    insta[x]=true;
    sta[++top]=x;
    int y;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        y=to[i];
        if(!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if(insta[y]) low[x]=min(low[x],dfn[y]);
    }
    if(low[x]==dfn[x])
    {
        do
        {
            y=sta[top--];
            insta[y]=false;
            be[y]=x;block[x].push_back(y);
        }while(y!=x);
    }
}
void update(int x,int z)
{
    if(z>=dp1[x])
    {
        dp2[x]=dp1[x];dp1[x]=z;
    }
    else if(z>dp2[x])
        dp2[x]=z;
}
void dfs2(int x,int fa)
{
    for(int y:tree[x])
    {
        if(y==fa) continue;
        dfs2(y,x);
        update(x,dp1[y]+1);
    }
}
void dfs3(int x,int fa)
{
    for(int y:tree[x])
    {
        if(y==fa) continue;
        if(dp1[x]-1==dp1[y])
            update(y,dp2[x]+1);
        else update(y,dp1[x]+1);
        dfs3(y,x);
    }
}
void print_block()
{
    for(int i=1;i<=n;++i)
    {
        printf("%d %d -----\n",i,be[i]);
        if(i==be[i])
        {
            for(int x:block[i]) printf("%d ",x);
            printf("\n");
        }
    }
}
void print_ru()
{
    for(int i=1;i<=n;++i) printf("%d ",ru[i]);
    printf("\n");
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) head[i]=-1;
    e=0;
    int x,y,z;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,i);
        if(z==2) addedge(y,x,i);
    }
    for(int i=1;i<=n;++i) vis[i]=insta[i]=false;
    has_circle=false;
    for(int i=1;i<=n;++i)
        if(!vis[i]) 
        {
            insta[i]=true;
            dfs1(i,-1);
            insta[i]=false;
        }
    if(has_circle) puts("Infinite");
    else
    {
        for(int i=1;i<=n;++i)
        {
            dfn[i]=low[i]=insta[i]=ru[i]=0;
        }
        cnt=top=0;
        for(int i=1;i<=n;++i)
            if(!dfn[i]) tarjan(i);
        // print_block();
        for(int x=1;x<=n;++x)
        {
            for(int i=head[x];i!=-1;i=pre[i])
            {
                int y=to[i];
                if(be[x]==be[y])
                    tree[x].push_back(y);
                else ++ru[be[y]];
            }
        }
        // print_ru();
        top=0;
        for(int i=1;i<=n;++i)
            if(be[i]==i&&ru[i]==0)
                sta[++top]=i;
        while(top)
        {
            int x=sta[top--];
            dfs2(x,-1);
            dfs3(x,-1);
            for(int xx:block[x])
            {
                for(int i=head[xx];i!=-1;i=pre[i])
                {
                    int y=to[i];
                    if(be[xx]!=be[y])
                    {
                        dp1[y]=max(dp1[y],dp1[xx]+1);
                        --ru[be[y]];
                        if(ru[be[y]]==0) sta[++top]=be[y];
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;++i) ans=max(ans,dp1[i]);
        printf("%d\n",ans);
    }
        return 0;
}
/*
3 3
1 2 1
2 3 2
3 1 1
*/

