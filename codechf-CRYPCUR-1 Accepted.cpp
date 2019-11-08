
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
#define M 100010
int head[N],to[M],pre[M];
int dfn[N],low[N],sta[N],block[N],chu[N],ru[N];
bool insta[N];
int a[M],b[M],c[M];
int n,m,e,cnt,scnt,top;
vector<int> g[N];
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
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
        ++scnt;
        do
        {
            y=sta[top--];
            insta[y]=false;
            block[y]=scnt;
        }while(y!=x);
    }
}
bool check(int z)
{
    int x,y;
    e=0;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;++i)
        if(c[i]<=z)
            addedge(a[i],b[i]);
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(insta,0,sizeof(insta));
    cnt=scnt=top=0;
    for(int i=1;i<=n;++i)
        if(!dfn[i]) tarjan(i);
    memset(chu,0,sizeof(chu));
    memset(ru,0,sizeof(ru));
    for(int i=1;i<=scnt;++i) g[i].clear();
    for(int i=1;i<=n;++i)
    {
        for(int j=head[i];j!=-1;j=pre[j])
        {
            x=block[i];y=block[to[j]];
            if(x!=y)
            {
                ++chu[x];++ru[y];
                g[x].push_back(y);
            }
        }
    }
    top=0;
    for(int i=1;i<=scnt;++i)
        if(ru[i]==0) sta[++top]=i;
    if(top>1) return false;
    while(top)
    {
        int x=sta[top--];
        for(auto y:g[x])
        {
            --ru[y];
            if(ru[y]==0) sta[++top]=y;
        }
        if(top>1) return false;
    }
    return true;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        int l=1,r=1e9,mid;
        while(l+1<r)
        {
             mid=l+r>>1;
             if(check(mid)) r=mid;
             else l=mid+1;
        }
        if(check(l)) printf("%d\n",l);
        else if(check(r)) printf("%d\n",r);
        else puts("Impossible");
    }
    return 0;
}

