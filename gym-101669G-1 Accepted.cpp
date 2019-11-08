
#include <bits/stdc++.h>
using namespace std;
#define N 10010
struct rec{
    double a,t;
}b[N];
double calc(int n)
{
    double ans=0,v=0;
    for(int i=1;i<=n;++i)
    {
        ans+=v*b[i].t+b[i].a*b[i].t*b[i].t/2;
        v+=b[i].a*b[i].t;
    }
    return ans;
}
bool cmp(rec &a,rec &b)
{
    return a.a>b.a;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf",&b[i].a,&b[i].t);
    double dis=calc(n);
    sort(b+1,b+n+1,cmp);
    printf("%.1f\n",calc(n)-dis);
    return 0;
}
/*
2
2 1
30 2
*/

