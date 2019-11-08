
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100010
typedef long long ll;
struct rec{
    int w,id;
}a[N];
int b[N];
int n,K;
ll m;
bool cmp(rec &a,rec &b)
{
    return a.w>b.w||a.w==b.w&&a.id<b.id;
}
bool check(int mid)
{
    for(int i=1;i<=mid;++i)
        b[i]=a[i].id;
    sort(b+1,b+mid+1);
    b[0]=0;
    ll cnt=0;
    int l=1,r=K;
    for(;r<=mid;++l,++r)
        cnt+=(ll)(b[l]-b[l-1])*(n-b[r]+1);
    return cnt>=m;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%lld",&n,&K,&m);
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i].w);
            a[i].id=i;
        }
        sort(a+1,a+n+1,cmp);
        int s=K,t=n,mid;
        while(s+1<t)
        {
            mid=s+t>>1;
            if(check(mid)) t=mid;
            else s=mid+1;
        }
        if(check(s)) printf("%d\n",a[s].w);
        else printf("%d\n",a[t].w);
    }
}
/*
10
5 3 1
2 3 1 5 4
3 3 1
5 8 2
5 5 1
1 2 3 4 5
10 3 12
1 9 8 2 5 7 6 4 3 1
*/

