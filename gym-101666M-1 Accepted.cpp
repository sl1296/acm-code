
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct rec{
    int x,y;
    rec(){}
    rec(int x,int y):x(x),y(y){}
}q[N],s,t;
int n;
int a[N];
bool cmp1(rec &a,rec &b)
{
    return a.y<b.y||a.y==b.y&&a.x<b.x;
}
bool cmp2(rec &a,rec &b)
{
    return a.y>b.y||a.y==b.y&&a.x<b.x;
}
int solve(int z)
{
    int cnt=0;
    for(int i=1;i<=z;++i)
    {
        int x=upper_bound(a+1,a+cnt+1,q[i].x)-a;
        if(x>cnt) a[++cnt]=q[i].x;
        else a[x]=q[i].x;
    }
    return cnt;
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d",&s.x,&s.y);
    scanf("%d%d",&t.x,&t.y);
    if(s.x>t.x) swap(s,t);
    int y1=min(s.y,t.y),y2=max(s.y,t.y);
    int x,y,z=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&x,&y);
        if(s.x<=x&&x<=t.x&&y1<=y&&y<=y2)
            q[++z]=rec(x,y);
    }
    if(s.y<t.y) sort(q+1,q+z+1,cmp1);
    else sort(q+1,q+z+1,cmp2);
    printf("%d\n",solve(z));
    return 0;
}

