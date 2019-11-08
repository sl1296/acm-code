
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
bool cmp(rec &a,rec &b)
{
    return min(a.r,b.l)>min(b.r,a.l);
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
            for(int i=0;i<strlen(st);++i)
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
//        for(int i=1;i<=n;++i) printf("%d %d ?\n",a[i].l,a[i].r);
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
1
2
(((
)))))
*/


