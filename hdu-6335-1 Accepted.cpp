
#include <bits/stdc++.h>
using namespace std;
#define N 110
typedef long long ll;
struct rec{
    int a,b,c;
}a[N];
bool cmp(rec &a,rec &b)
{
    return a.c<b.c;
}
int n,m;
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d",&n,&m);
        ll tot=0,tmp,z=0,ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d",&a[i].a,&a[i].b);
            a[i].c=a[i].b+1;
            tot=0;
            tot+=(ll)a[i].a*(m/(a[i].a+a[i].b));
            tmp=m%(a[i].a+a[i].b);
            if(tmp>a[i].b) tot+=tmp-a[i].b;
            z+=tot;
            if(z>=m)
            {
                ++ans;z-=m;
            }
        }
        if(z) ++ans;
        sort(a+1,a+n+1,cmp);
        ll ans2=0,tt;
        tmp=1;
        for(int i=1;i<=n;++i)
        {
            tmp*=a[i].c;
            if(tmp>m)
            {
                tmp/=a[i].c;
                tt=m/tmp;
                break;

            }
            ans2=i;
        }
        printf("%lld\n",ans2);
    }
    return 0;
}
/*
3
3 1
1 3
1 2
1 1
3 5
1 3
1 3
1 3
5 50
1 1
2 3
3 2
5 3
3 5
*/

