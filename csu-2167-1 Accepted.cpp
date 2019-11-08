
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 100010
#define M 200010
#define lx x<<1
#define rx x<<1|1
#define lson lx,s,mid
#define rson rx,mid+1,t
typedef long long ll;
struct rec{
    int l,r,k;
    rec(){}
    rec(int k,int l,int r):k(k),l(l),r(r){}
}q[N];
int seg[3][M*3],lazy[3][M*3];
int a[3][M],num[3];
void build(int k,int x,int s,int t)
{
    seg[k][x]=0;lazy[k][x]=0;
    if(s==t) return;
    int mid=s+t>>1;
    build(k,lson);build(k,rson);
}
void pushdown(int k,int x,int s,int t)
{
    if(lazy[k][x])
    {
        if(s!=t)
        {
            int mid=s+t>>1;
            seg[k][lx]=a[k][mid]-a[k][s-1];lazy[k][lx]=1;
            seg[k][rx]=a[k][t]-a[k][mid];lazy[k][rx]=1;
        }
        lazy[k][x]=0;
    }
}
void update(int k,int x,int s,int t,int l,int r)
{
//    printf("%d %d %d %d @@\n",s,t,l,r);
    if(l<=s&&t<=r)
    {
//        printf("%d %d %d ##\n",s,t,a[k][t]-a[k][s-1]);
        seg[k][x]=a[k][t]-a[k][s-1];lazy[k][x]=1;
        return;
    }
    pushdown(k,x,s,t);
    int mid=s+t>>1;
    if(l<=mid) update(k,lson,l,r);
    if(mid<r) update(k,rson,l,r);
    seg[k][x]=seg[k][lx]+seg[k][rx];
}
int query(int k,int x,int s,int t,int l,int r)
{
    if(l<=s&&t<=r) return seg[k][x];
    pushdown(k,x,s,t);
    int mid=s+t>>1,q=0;
    if(l<=mid) q+=query(k,lson,l,r);
    if(mid<r) q+=query(k,rson,l,r);
    return q;
}
int main(){
    int z,n,m,n1,n2;
    while(~scanf("%d%d%d",&n,&m,&z)){
        int k,x,y;
        memset(num,0,sizeof(num));
        for(int i=1;i<=z;++i){
            scanf("%d%d%d",&k,&x,&y);
            q[i]=rec(k,x,y);
            a[k][++num[k]]=x-1;
            a[k][++num[k]]=y;
        }
        for(int i=1;i<=2;++i)
        {
            sort(a[i]+1,a[i]+num[i]+1);
            num[i]=unique(a[i]+1,a[i]+num[i]+1)-a[i]-1;
//            for(int j=1;j<=num[i];++j) printf("%d ",a[i][j]);
//            printf(" ---- %d\n",i);
            build(i,1,0,num[i]);
        }
//        printf("ok\n");
        ll ans;
        for(int i=1;i<=z;++i)
        {
            k=q[i].k;
            q[i].l=lower_bound(a[k]+1,a[k]+num[k]+1,q[i].l-1)-a[k];
            q[i].r=lower_bound(a[k]+1,a[k]+num[k]+1,q[i].r)-a[k];
            update(k,1,0,num[k],q[i].l+1,q[i].r);
            x=seg[1][1];y=seg[2][1];
//            printf("%d %d %d %d %d %d %d ?\n",i,q[i].l,q[i].r,x,y,n,m);
            if(x==0) ans=(ll)n*(m-y)+y;
            else if(y==0) ans=(ll)m*(n-x)+x;
            else ans=(ll)n*m-(ll)x*m-(ll)y*n+(ll)x*y+1;
            printf("%lld\n",ans);
        }
    }
    return 0;
}

