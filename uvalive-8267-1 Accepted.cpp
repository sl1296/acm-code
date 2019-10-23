
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 1010
#define M 100010
int inf=0x3f3f3f3f;
int head[N],to[M],pre[M],cap[M],dis[N],q[N],vis[N],cur[N];
int n,m,e,cnt;
void addedge(int x,int y,int c)
{
	to[e]=y;cap[e]=c;pre[e]=head[x];head[x]=e++;
	to[e]=x;cap[e]=0;pre[e]=head[y];head[y]=e++;
}
bool bfs(int s,int t)
{
	int l=0,r=0;
	memset(dis,-1,sizeof(dis));
	q[l]=s;dis[s]=0;
	int x,y;
	while(l<=r)
	{
		x=q[l++];
		for(int i=head[x];i!=-1;i=pre[i])
		{
			y=to[i];
			if(dis[y]!=-1||cap[i]==0) continue;
			dis[y]=dis[x]+1;
			if(y==t) return true;
			q[++r]=y;
		}
	}
	return false;
}
int dfs(int x,int t,int f)
{
	if(x==t||f==0) return f;
	int ans=0,flow;
	for(int &i=cur[x];i!=-1;i=pre[i])
	{
		if(dis[x]+1==dis[to[i]]&&(flow=dfs(to[i],t,min(f,cap[i])))>0)
		{
			cap[i]-=flow;cap[i^1]+=flow;ans+=flow;f-=flow;
			if(f==0) break;
		}
	}
	if(ans==0) dis[x]=-1;
	return ans;
}
int dinic(int s,int t)
{
	int ans=0,f;
	while(bfs(s,t))
	{
	    for(int i=0;i<=n;++i) cur[i]=head[i];
		ans+=dfs(s,t,inf);
	}
	return ans;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    int s,t,k;
    while(ca--)
    {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&k);
        memset(head,-1,sizeof(head));
        e=0;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(x,y,1);addedge(y,x,1);
        }
        printf("%d\n",dinic(s,t)*((k+2)/3));
    }
	return 0;
}
/*
2
5 7 1 3 10
1 2
2 3
1 4
4 3
1 5
5 3
2 4
5 7 1 3 10
1 2
2 3
1 4
4 3
1 5
5 3
2 4
*/

