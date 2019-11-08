
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct rec{
    int l,r;
    rec(){}
    rec(int l,int r):l(l),r(r){}
}a[N];
char st[N];
int n;
bool cmp(const rec &a,rec &b)
{
    int d1=a.l-a.r,d2=b.l-b.r;
    if(d1<0&&d2<0)
        return a.l<b.l||a.l==b.l&&a.r>b.r;
    else if(d1>0&&d2>0)
        return a.r>b.r||a.r==b.r&&a.l<b.l;
    else return d1<d2;
}
int main()
{
    int ca,ans,l,r,tmp;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%s",st);
            l=0;r=0;
            int len=strlen(st);
            for(int i=0;i<len;++i)
            {
                if(st[i]=='(') ++r;
                else
                {
                    if(r)
                    {
                        --r;
                        ans+=2;
                    }
                    else ++l;
                }
            }
            a[i]=rec(l,r);
        }
        sort(a+1,a+n+1,cmp);
//        for(int i=1;i<=n;++i) printf("%d %d ?\n",a[i],l,a[i].r);
        r=0;
        for(int i=1;i<=n;++i)
        {
            if(r>=a[i].l)
            {
                r-=a[i].l;
                ans+=a[i].l*2;
                r+=a[i].r;
            }
            else
            {
                ans+=r*2;
                r=a[i].r;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
2
))(((
)))(((((
3
)
))
)))(((
*/

