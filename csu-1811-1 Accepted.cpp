
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define N 100010
struct rec{
    int x,id;
    rec(){}
    rec(int x,int id):x(x),id(id){}
};
struct seg{
    int l,r;
    seg(){}
    seg(int l,int r):l(l),r(r){}
}q[N];
vector<rec> g[N];
int n,cnt;
int c[N],r[N],dfn[N],id[N],be[N],a[N],b[N],ans[N],t1,t2;
void dfs(int x,int fa)
{
    dfn[++cnt]=x;
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i].x;
        if(y==fa) continue;
        id[y]=g[x][i].id;
        dfs(y,x);
    }
    // printf("%d %d !\n",x,cnt);
    r[x]=cnt;
}
bool cmp(seg &a,seg &b)
{
    return be[a.l]<be[b.l]||be[a.l]==be[b.l]&&a.r<b.r;
}
bool check(int x)
{
    return 1<=x&&x<=n;
}
void add(int i)
{
    if(!check(i)) return;
    // printf("add %d\n",i);
    int co=c[dfn[i]];
    ++a[co];
    if(a[co]==1) ++t1;
    --b[co];
    if(b[co]==0) --t2;
}
void sub(int i)
{
    if(!check(i)) return;
    // printf("sub %d\n",i);
    int co=c[dfn[i]];
    --a[co];
    if(a[co]==0) --t1;
    ++b[co];
    if(b[co]==1) ++t2;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i) a[i]=b[i]=0;
        for(int i=1;i<=n;++i) scanf("%d",&c[i]),++b[c[i]];
        int tot=0;
        for(int i=1;i<=n;++i) 
            if(b[i]) ++tot;
        for(int i=1;i<=n;++i)
        {
            g[i].clear();
        }
        int x,y;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&x,&y);
            g[x].push_back(rec(y,i));
            g[y].push_back(rec(x,i));
        }
        cnt=0;
        dfs(1,0);
        // printf("ok\n");
        // for(int i=1;i<=n;++i) printf("%d ",dfn[i]);
        // printf("\n");
        // for(int i=1;i<=n;++i) printf("%d ",r[dfn[i]]);
        // printf("\n");
        // for(int i=1;i<=n;++i) printf("%d ",id[i]);
        // printf("\n");
        int unit=sqrt(n);
        for(int i=1;i<=n;++i) be[i]=(i-1)/unit+1;
        for(int i=2;i<=n;++i)
            q[i-1]=seg(i,r[dfn[i]]);
        // for(int i=1;i<n;++i) printf("seg %d %d\n",q[i].l,q[i].r);
        sort(q+1,q+n,cmp);
        // printf("ok\n");
        int l=0,r=0;
        t1=0;t2=tot;
        for(int i=1;i<n;++i)
        {
            // printf("%d !!!\n",i);
            while(l<q[i].l)
            {
                if(l<=r) sub(l); 
                ++l;
            }
            while(l>q[i].l)
            {
                --l;
                if(l<=r) add(l);
            }
            while(r<q[i].r)
            {
                ++r;
                if(l<=r) add(r); 
            }
            while(r>q[i].r)
            {
                if(l<=r) sub(r);
                --r;
            }
            // printf("%d %d %d %d %d ?\n",q[i].l,q[i].r,t1,t2,tot);
            ans[id[dfn[l]]]=t1-(tot-t2);
        }
        for(int i=1;i<n;++i) printf("%d\n",ans[i]);
    }
    return 0;
}
/*
4
1 2 2 1
1 2
2 3
3 4
5
1 1 2 1 2
1 3
2 3
3 5
4 5
*/

