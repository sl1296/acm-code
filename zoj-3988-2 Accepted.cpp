
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 6010
#define M 4000010
int n;
int link[N],vis[N],a[N];
vector<int>g[N];
bool prime[M],f[N];
bool dfs(int x,int fa)
{
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(vis[y]!=fa)
        {
            vis[y]=fa;
            if(link[y]==-1||dfs(link[y],fa))
            {
                link[y]=x;link[x]=y;
                return true;
            }
        }
    }
    return false;
}
void init()
{
	memset(prime,1,sizeof(prime));
	for(int i=2;i<M;++i)
		if(prime[i])
		{
			for(int j=i+i;j<M;j+=i)
				prime[j]=false;
		}
}
int main()
{
	init();
	int K,ca;
	scanf("%d",&ca);
    while(ca--)
    {
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
        for(int i=1;i<=n;++i) 
		{
			g[i].clear();
			vis[i]=link[i]=-1;
			f[i]=false;
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				if(prime[a[i]+a[j]])
				{
                    f[i]=f[j]=true;
                    if(a[i]==1&&a[j]==1) continue;
					if(a[i]&1) g[i].push_back(j);
					else g[j].push_back(i);
					
				}
        int ans=0;
        for(int i=n;i>=1;--i)
            if(f[i]&&(a[i]&1)&&dfs(i,i)) ++ans;
		int cnt=0;
		for(int i=1;i<=n;++i)
			if(a[i]==1&&link[i]==-1) ++cnt;
		ans+=cnt/2;
		if(K<=ans) printf("%d\n",K*2);
		else
		{
			int num=0;
			for(int i=1;i<=n;++i)
				if(f[i]) ++num;
			printf("%d\n",ans*2+min(num-ans*2,K-ans));
		}
    }
    return 0;
}

