
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define N 410
#define M 200010
const int inf=0x3f3f3f3f;
struct Edge{
    int x,c,w,nxt;
    Edge(){}
    Edge(int x,int c,int w,int nxt):x(x),c(c),w(w),nxt(nxt){}
}edge[M];
int head[N],dis[N],pre[N],pree[N];
bool inque[N];
int S[N],T[N],w[N],op[N];
int n,m,K,W,e,src,sink;
void addedge(int x,int y,int c,int w)
{
    edge[e]=Edge(y,c,w,head[x]);head[x]=e++;
    edge[e]=Edge(x,0,-w,head[y]);head[y]=e++;
}
bool spfa()
{
    int x,y,w;
    queue<int> que;
    memset(dis,0x3f,sizeof(dis));
    memset(inque,0,sizeof(inque));
    que.push(src);dis[src]=0;inque[src]=true;
    while(!que.empty())
    {
        x=que.front();
        que.pop();inque[x]=false;
        for(int i=head[x];i!=-1;i=edge[i].nxt)
        {
            y=edge[i].x;w=edge[i].w;
            if(edge[i].c>0&&dis[x]+w<dis[y])
            {
                dis[y]=dis[x]+w;pre[y]=x;pree[y]=i;
                if(!inque[y]&&y!=sink)
                {
                    que.push(y);inque[y]=true;
                }
            }
        }
    }
    return dis[sink]<inf;
}
int mincostflow()
{
    int ans=0,minc,x,d;
    while(spfa())
    {
        minc=inf;x=sink;
        while(x!=src)
        {
            minc=min(minc,edge[pree[x]].c);
            x=pre[x];
        }
        x=sink;
        while(x!=src)
        {
            edge[pree[x]].c-=minc;
            edge[pree[x]^1].c+=minc;
            x=pre[x];
        }
        ans+=minc*dis[sink];
    }
    return ans;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        e=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d%d%d",&n,&m,&K,&W);
        for(int i=1;i<=m;++i)
            scanf("%d%d%d%d",&S[i],&T[i],&w[i],&op[i]);
        for(int i=1;i<=m;++i)
           addedge(i,i+m,1,0);
        for(int i=1;i<=m;++i)
            for(int j=1;j<=m;++j)
                if(T[i]<=S[j])
                {
                    if(op[i]!=op[j])
                        addedge(i+m,j,inf,-w[j]);
                    else addedge(i+m,j,inf,-(w[j]-W));
                }
        src=2*m+1;sink=2*m+2;
        addedge(src,0,K,0);
        for(int i=1;i<=m;++i)
        {
            addedge(0,i,inf,-w[i]);
            addedge(i+m,sink,inf,0);
        }
        printf("%d\n",-mincostflow());
    }
    return 0;
}
/*

*/

