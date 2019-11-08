
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct rec{
    int x,y;
    rec(){}
    rec(int x,int y):x(x),y(y){}
}a[2][N];
int b[N];
set<int> se[N];
int n,t;
bool cmp(rec &a,rec &b)
{
    return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int calc(rec a[])
{
    sort(a+1,a+n+1,cmp);
    int mx=0,cnt=1;
    for(int i=2;i<=n;++i)
        if(a[i].x!=a[i-1].x)
        {
            mx=max(mx,cnt);
            cnt=1;
        }
        else ++cnt;
    mx=max(mx,cnt);
    return mx;
}
bool check(int x,int y,int len)
{
    int k=lower_bound(b+1,b+t+1,y)-b;
    if(k>t||b[k]!=y) return false;
    int x1=x-len,x2=x+len;
    if(se[k].find(x1)==se[k].end()) return false;
    if(se[k].find(x2)==se[k].end()) return false;
    return true;
}
int solve(rec a[])
{
    for(int i=1;i<=n;++i) b[i]=a[i].y;
    sort(b+1,b+n+1);
    t=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;++i)
    {
        int tmp=lower_bound(b+1,b+t+1,a[i].y)-b;
        se[tmp].insert(a[i].x);
    }
    int ans=0,l=1,r;
    for(int i=1;i<=n;++i)
    {
        if(i==n||a[i].x!=a[i+1].x)
        {
            r=i;
            for(int j=l;j<r;++j)
                for(int k=r;k>j;--k)
                {
                    if(a[k].y-a[j].y<=ans) break;
                    if((a[k].y-a[j].y)&1) continue;
                    if(check(a[j].x,(a[k].y+a[j].y)/2,(a[k].y-a[j].y)/2))
                        ans=a[k].y-a[j].y;
                }
            l=i+1;
        }
    }
    for(int i=1;i<=t;++i) se[i].clear();
    return ans/2;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int x,y;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&x,&y);
            a[0][i]=rec(x,y);
            a[1][i]=rec(y,x);
        }
        int k=0;
        if(calc(a[0])>calc(a[1])) k=1;
        printf("%d\n",solve(a[k]));
    }
}

