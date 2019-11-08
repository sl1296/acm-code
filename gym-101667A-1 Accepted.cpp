
#include <bits/stdc++.h>
using namespace std;
#define N 5010
int head[N],pre[N*2],to[N*2];
int D[N][N],E[N][N];
int n,e;
void addedge(int x,int y)
{
	to[e]=y;pre[e]=head[x];head[x]=e++;
}
void dfs(int x,int fa)
{
	int sum[N];
	memset(sum,0,sizeof(sum));
	for(int i=head[x];i!=-1;i=pre[i])
	{
		int y=to[i];
		if(y==fa) continue;
		dfs(y,x);
		for(int j=0;j<=n;++j)
			sum[j]+=E[y][j];
	}
	for(int i=head[x];i!=-1;i=pre[i])
	{
		int y=to[i];
		if(y==fa) continue;
		for(int j=0;j<n;++j)
			D[x][j]=min(D[x][j],D[y][j+1]+sum[j]-E[y][j]);
	}
	for(int i=1;i<=n;++i) D[x][i]=min(D[x][i],i+sum[i]);
	for(int i=n-1;i>=0;--i) D[x][i]=min(D[x][i],D[x][i+1]);
	for(int i=1;i<=n;++i) E[x][i]=min(E[x][i],sum[i-1]);
	E[x][0]=D[x][0];
	for(int i=1;i<=n;++i) E[x][i]=min(E[x][i],E[x][i-1]);		
}
int main()
{
	scanf("%d",&n);
	memset(head,-1,sizeof(head));
	e=0;
	int x,y;
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y);
		addedge(y,x);
	}
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
			D[i][j]=E[i][j]=n;
	dfs(1,0);
	printf("%d\n",D[1][0]);
	return 0;
}

