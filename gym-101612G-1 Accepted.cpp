
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int head[N],to[N*2],pre[N*2],fa[N],dfn[N],low1[N],low2[N],end1[N],end2[N],node[N];
int n,m,e,cnt;
bool flag;
vector<int> path;
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
void init()
{
    for(int i=1;i<=n;++i) 
    {
        head[i]=-1;dfn[i]=0;
    }
    e=cnt=0;
}
void update(int x,int d,int y)
{
    if(d<low1[x])
    {
        low2[x]=low1[x];end2[x]=end1[x];
        low1[x]=d;end1[x]=y;
    }
    else if(d<low2[x])
    {
        low2[x]=d;end2[x]=y;
    }
}
void get_path(int s,int t,bool rev)
{
    vector<int> vec;
    for(int i=s;i!=t;i=fa[i]) vec.push_back(i);
    vec.push_back(t);
    if(rev) reverse(vec.begin(),vec.end());
    for(int x:vec) path.push_back(x);
}
void print_path()
{
    printf("%d ",path.size());
    for(int x:path) printf("%d ",x);
    printf("\n");
}
void tarjan(int x,int p)
{
    dfn[x]=low1[x]=low2[x]=++cnt;
    node[cnt]=x;end1[x]=end2[x]=x;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        int y=to[i];
        if(y==p) continue;
        if(!dfn[y])
        {
            fa[y]=x;
            tarjan(y,x);
            update(x,low1[y],end1[y]);
        }
        else if(dfn[y]<dfn[x])
            update(x,dfn[y],x);
    }
    if(!flag&&low2[x]<dfn[x])
    {
        int s=x,t=node[low2[x]];
        printf("%d %d\n",s,t);

        path.clear();
        get_path(s,t,false);
        print_path();
        
        path.clear();
        get_path(end2[x],s,true);
        path.push_back(t);
        print_path();

        path.clear();
        get_path(end1[x],s,true);
        get_path(t,node[low1[x]],true);
        print_path();

        flag=true;
    }
}
int main()
{
    freopen("grand.in","r",stdin);
    freopen("grand.out","w",stdout);
    int ca,x,y;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y);addedge(y,x);
        }
        flag=false;
        for(int i=1;i<=n;++i)
            if(!dfn[i]) tarjan(i,-1);
        if(!flag) puts("-1");
    }
    return 0;
}
/*
2
6 6
3 6
3 4
1 4
1 2
1 3
2 3
3 1
1 2
*/

