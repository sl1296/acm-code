
#include <bits/stdc++.h>
using namespace std;
#define N 20
const double eps=1e-6;
const double inf=1e8;
struct Point{
    int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    Point operator-(const Point &a)const
    {
        return Point(x-a.x,y-a.y);
    }
    int operator^(const Point &a)const
    {
        return x*a.y-y*a.x;
    }
}P[N];
double a[N],b[N];
int n,ans,z;
bool vis[N];
bool cmp(double x,double y)
{
    return x<y;
}
void dfs(int dep)
{
//    printf("%d ?\n",dep);
    if(dep>z)
    {
        for(int i=1;i<=z;++i) b[i]=a[i];
        sort(b+1,b+z+1,cmp);
//        for(int i=1;i<=z;++i) printf("%.6f ",b[i]);printf("\n");
        int tmp=0,cnt=1;
        for(int i=2;i<=z;++i)
            if(fabs(b[i]-b[i-1])<eps) ++cnt;
            else
            {
                tmp+=cnt*(cnt-1)/2;
                cnt=1;
            }
//        printf("%d %d !\n",tmp,cnt);
        tmp+=cnt*(cnt-1)/2;
//        printf("%d #\n",tmp);
        ans=max(ans,tmp);
        return;
    }
    int k;
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            vis[i]=true;k=i;break;
        }
    for(int i=1;i<=n;++i)
        if(!vis[i])
        {
            vis[i]=true;
            if(P[i].x==P[k].x) a[dep]=inf;
            else a[dep]=(double)(P[i].y-P[k].y)/(P[i].x-P[k].x);
            dfs(dep+1);
            vis[i]=false;
        }
    vis[k]=false;
}
int main()
{
    scanf("%d",&n);z=n/2;
    for(int i=1;i<=n;++i)
        scanf("%d%d",&P[i].x,&P[i].y);
    ans=0;
    dfs(1);
    printf("%d\n",ans);
    return 0;
}


