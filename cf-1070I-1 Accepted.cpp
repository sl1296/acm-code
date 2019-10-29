
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2010
#define M 100010
int inf=0x3f3f3f3f;
int head[N],to[M],pre[M],cap[M],dis[N],q[N],vis[N],cur[N],du[N],col[N];
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
	    for(int i=0;i<=t;++i) cur[i]=head[i];
		ans+=dfs(s,t,inf);
	}
	return ans;
}
int main()
{
    int k,ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d",&n,&m,&k);
        memset(head,-1,sizeof(head));
        e=0;
        memset(du,0,sizeof(du));
        int s=0,t=n+m+1;
        for(int i=1;i<=m;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,n+i,1);addedge(b,n+i,1);
            addedge(n+i,t,1);
            ++du[a];++du[b];
        }
        int sum=0;
        for(int i=1;i<=n;++i) 
            if(du[i]>k)
            {
                addedge(s,i,(du[i]-k)*2);
                sum+=(du[i]-k)*2;
            }
        int flow=dinic(s,t);
        memset(col,0,sizeof(col));
        if(flow==sum)
        {
            for(int i=1;i<=m;++i) col[i]=i;
            int cnt=0,c=m+1;
            for(int x=1;x<=n;++x)
                for(int i=head[x];i!=-1;i=pre[i])
                    if(to[i]>n&&cap[i]==0)
                    {
                        col[to[i]-n]=c;
                        ++cnt;
                        if(cnt==2)
                        {
                            cnt=0;++c;
                        }
                    }
        }
        for(int i=1;i<=m;++i) 
        {
            printf("%d",col[i]);
            if(i==m) printf("\n");
            else printf(" ");
        }
    }
	return 0;
}

