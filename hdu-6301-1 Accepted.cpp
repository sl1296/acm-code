
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define N 100010
#define lx x<<1
#define rx x<<1|1
#define lson lx,s,mid
#define rson rx,mid+1,t
const int inf=0x3f3f3f3f;
int n,m;
pii a[N],b[N];
int seg[N*4],ans[N];
void build(int x,int s,int t)
{
    if(s==t)
    {
        seg[x]=s;
        return;
    }
    int mid=s+t>>1;
    build(lson);build(rson);
    seg[x]=min(seg[lx],seg[rx]);
}
void updata(int x,int s,int t,int id,int w)
{
    if(s==t)
    {
        seg[x]=w;
        return;
    }
    int mid=s+t>>1;
    if(id<=mid) updata(lson,id,w);
    else updata(rson,id,w);
    seg[x]=min(seg[lx],seg[rx]);
}
bool cmp(pii a,pii b)
{
    return a.first<b.first||a.first==b.first&&a.second>b.second;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        if(m==0)
        {
            for(int i=1;i<=n;++i)
            {
                printf("%d",i);
                if(i==n) printf("\n");
                else printf(" ");
            }
            continue;
        }
        build(1,1,n);
        int l,r;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&l,&r);
            a[i]=pii(l,r);
        }
        sort(a+1,a+m+1,cmp);
        int t=1;b[1]=a[1];
        for(int i=2;i<=m;++i)
            if(a[i].second>b[t].second)
                b[++t]=a[i];
        b[++t]=pii(n+1,n+1);
//        for(int i=1;i<=t;++i) printf("%d %d #\n",b[i].first,b[i].second);
        int j=1;
        for(int i=1;i<=n;++i)
        {
            if(i>b[j].second)
            {
                l=b[j].first;
                r=b[j].second;
                if(j<t) r=min(r,b[j+1].first-1);
//                printf("%d %d %d ---\n",i,l,r);
                for(int k=l;k<=r;++k)
                {
//                    printf("%d %d %d ?\n",i,k,ans[k]);
                    updata(1,1,n,ans[k],ans[k]);
                }
                ++j;
            }
            ans[i]=seg[1];
            updata(1,1,n,ans[i],inf);
            if(i<b[j].first) updata(1,1,n,ans[i],ans[i]);
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d",ans[i]);
            if(i==n) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}
/*
10
10 1
3 6
10 4
5 8
2 6
3 7
2 5
*/

