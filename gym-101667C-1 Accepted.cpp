
#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define M 600010
int head[N],to[M],pre[M],du[N],a[N],d[N];
int n,m,e;
void addedge(int x,int y)
{
    to[e]=y;pre[e]=head[x];head[x]=e++;
}
bool cmp(int x,int y)
{
    return du[x]<du[y];
}
int main()
{
    scanf("%d%d",&n,&m);
    memset(head,-1,sizeof(head));
    e=0;
    int x,y;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
        ++du[x];++du[y];
    }
    for(int i=0;i<n;++i)
    {
        a[i]=i;d[i]=1;
    }
    sort(a,a+n,cmp);
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        for(int j=head[x];j!=-1;j=pre[j])
        {
            int y=to[j];
            if(du[x]>du[y])
            {
                d[x]=max(d[x],d[y]+1);
            }
        }
        ans=max(ans,d[x]);
    }
    printf("%d\n",ans);
    return 0;
}
/*
6 9
0 1
0 4
1 2
1 3
1 4
1 5
2 5
3 4
4 5
*/

