
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 200010
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
struct Edge{
    int c,id;
    Edge(){}
    Edge(int c,int id):c(c),id(id){}
};
int a[M],b[M];
vector<Edge> g[N];
int n,m,e,flag,cnt,len=M*3;
int head[M*3],to[M*8],pre[M*8],w[M*8];
int que[M*3],d[M*3];
bool inque[M*3];
bool cmp(Edge &a,Edge &b)
{
    return a.c<b.c;
}
void addedge(int x,int y,int z)
{
    to[e]=y;w[e]=z;pre[e]=head[x];head[x]=e++;
}
void add(int &x)
{
    ++x;
    if(x==len) x=0;
}
int solve()
{
    int s=0,t=0;
    for(int i=1;i<=cnt;++i)
    {
        if(i<=m&&(a[i]==1||b[i]==1))
        {
            d[i]=0;inque[i]=true;
            que[t]=i;add(t);
        }
        else
        {
            d[i]=inf;inque[i]=false;
        }
    }
    pii p;
    int x,z,xx,zz;
    while(s!=t)
    {
        x=que[s];add(s);inque[x]=false;
        for(int i=head[x];i!=-1;i=pre[i])
        {
            xx=to[i];
            if(d[x]+w[i]<d[xx])
            {
                d[xx]=d[x]+w[i];
                if(!inque[xx])
                {
                    que[t]=xx;add(t);
                    inque[xx]=true;
                }
            }
        }
    }
    int ans=inf;
    for(int i=1;i<=m;++i)
    {
//        printf("%d %d !\n",i,d[i]);
        if(a[i]==n||b[i]==n)
            ans=min(ans,d[i]);
    }
    if(ans==inf) return -1;
    else return ans/2+1;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;++i) g[i].clear();
        int x,y,z;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            a[i]=x;b[i]=y;
            g[x].push_back(Edge(z,i));
            g[y].push_back(Edge(z,i));
            head[i]=-1;
        }
        cnt=m;e=0;
        for(x=1;x<=n;++x)
        {
            sort(g[x].begin(),g[x].end(),cmp);
            head[++cnt]=-1;
            if(g[x].size())
            {
                Edge e=g[x][0];
                addedge(e.id,cnt,1);
                addedge(cnt,e.id,1);
            }
            for(int i=1;i<g[x].size();++i)
            {
                Edge e1=g[x][i],e2=g[x][i-1];
                if(e1.c==e2.c)
                {
                    addedge(e1.id,e2.id,0);
                    addedge(e2.id,e1.id,0);
                }
                else
                {
                    addedge(e1.id,cnt,1);
                    addedge(cnt,e1.id,1);
                }
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}

