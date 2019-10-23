
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define N 250
#define M 20010   
typedef pair<int,int> pii;
int inf=0x3f3f3f3f;
int head[N],to[M],pre[M],cap[M],dis[N],q[N],vis[N],cur[N];
int n,m,e,cnt;
map<pii,int> mp;
void addedge(int x,int y,int c)
{
	to[e]=y;cap[e]=c;pre[e]=head[x];head[x]=e++;
	to[e]=x;cap[e]=0;pre[e]=head[y];head[y]=e++;
}
bool bfs(int s,int t)
{
	int l=0,r=0;
    for(int i=0;i<=t;++i) dis[i]=-1;
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
int a[10010];
int main()
{
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(int i=0;i<=m*(m+1)/2+m+1;++i) head[i]=-1;
        e=0;
        mp.clear();
        int s=0,z=0;
        for(int i=1;i<=m;++i)
            for(int j=i;j<=m;++j)
            {
                mp[make_pair(i,j)]=++z;
            }
        for(int i=1;i<=m;++i)
            for(int j=i;j<=m;++j)
            {
                int id=mp[make_pair(i,j)];
                addedge(s,id,0);
                for(int k=i;k<=j;++k)
                    addedge(id,k+z,inf);
            }
        int t=z+m+1;    
        for(int i=1;i<=m;++i)
            addedge(i+z,t,0);
        int x,y,flow=0;
        vector<int> ans;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&x,&y);
            int id=mp[make_pair(x,y)];
            for(int j=head[s];j!=-1;j=pre[j])
                if(to[j]==id)
                {
                    ++cap[j];break;
                }
            flow+=dinic(s,t);
            if(flow!=i)
            {
                ans.push_back(i);
                for(int x=z+1;x<=z+m;++x)
                    for(int j=head[x];j!=-1;j=pre[j])
                        if(to[j]==t) ++cap[j];
            }
        }
        printf("%d",ans[0]);
        for(int i=1;i<ans.size();++i) printf(" %d",ans[i]);
        printf("\n");
    }
	return 0;
}
/*
3 3
1 1
1 1
1 1
3 3
1 2
2 3
1 1
3 3
1 2
1 2
1 2
0
*/

