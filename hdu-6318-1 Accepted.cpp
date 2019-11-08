
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int n,a[N],c[N];
ll ans;
void Sort(int l,int r)
{
    int mid=(l+r)/2,i,j,tmp;
    if(r>l)
    {
        Sort(l,mid);
        Sort(mid+1,r);
        tmp=l;
        for(i=l,j=mid+1;i<=mid&&j<=r;)
        {
            if(a[i]>a[j])
            {
                c[tmp++]=a[j++];
                ans+=mid-i+1;
            }
            else c[tmp++]=a[i++];
        }
        if(i<=mid) for(;i<=mid;) c[tmp++]=a[i++];
        if(j<=r) for(;j<=r;) c[tmp++]=a[j++];
        for(i=l;i<=r;i++) a[i]=c[i];
    }
}
int main()
{
    ll x,y;
    while(scanf("%d%lld%lld",&n,&x,&y)!=EOF)
    {
        for(int i=1;i<=n;++i) scanf("%d",&a[i]);
        ans=0;
        Sort(1,n);
        printf("%lld\n",min(x,y)*ans);
    }
    return 0;
}

