
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
#define lx x<<1
#define rx x<<1|1
#define lson lx,s,mid
#define rson rx,mid+1,t
typedef long long ll;
ll seg[N*4];
int a[N];
int n;
ll mod;
void build(int x,int s,int t)
{
    seg[x]=1;
    if(s==t) return;
    int mid=s+t>>1;
    build(lson);build(rson);
}
void update(int x,int s,int t,int id,int w)
{
    if(s==t)
    {
        seg[x]=w;return;
    }
    int mid=s+t>>1;
    if(id<=mid) update(lson,id,w);
    else update(rson,id,w);
    seg[x]=seg[lx]*seg[rx]%mod;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%I64d\n",&n,&mod);
        build(1,1,n);
        char st[10];
        for(int i=1;i<=n;++i)
        {
            scanf("%s%d",st,&a[i]);
            if(st[0]=='M')
            {
                update(1,1,n,i,a[i]);
                printf("%I64d\n",seg[1]);
            }
            else
            {
                update(1,1,n,a[i],1);
                printf("%I64d\n",seg[1]);
            }
        }
    }
    return 0;
}

