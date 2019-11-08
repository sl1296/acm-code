
#include<bits/stdc++.h>
using namespace std;
int a[20],b[100];
int ys[100],ysn;
#define N 70
#define M 5010
int inf=0x3f3f3f3f;
int head[N],to[M],pre[M],cap[M],dis[N],q[N],vis[N],cur[N];
int e,cnt;
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
int main(){
    for(int i=0,ii=1;i<=3;++i,ii*=2){
        for(int j=0,jj=ii;j<=2;++j,jj*=3){
            for(int k=0,kk=jj;k<=1;++k,kk*=5){
                for(int l=0,ll=kk;l<=1;++l,ll*=7){
                    ys[ysn++]=ll;
                }
            }
        }
    }
    sort(ys,ys+ysn);
//    printf("%d\n",ysn);
//    for(int i=0;i<ysn;++i)printf("%d ",ys[i]);
    int cas;
    scanf("%d",&cas);
    while(cas--){
        memset(head,-1,sizeof(head));
        e=0;
        int m;
        scanf("%d",&m);
        int s=0,t=59;
        for(int i=0;i<ysn;++i)b[i]=m/ys[i];
        for(int i=ysn-1;i>=0;--i){
            for(int j=0;j<i;++j){
                if(ys[i]%ys[j]==0)b[j]-=b[i];
            }
            addedge(s,i,b[i]);
            for(int j=1;j<=10;++j){
                if(ys[i]%j==0){
                    addedge(i,j+48,b[i]);
                }
            }
        }
        for(int i=1;i<=10;++i){
            scanf("%d",&a[i]);
            addedge(i+48,t,a[i]);
        }
        printf("%d\n",dinic(s,t));
    }
    return 0;
}

