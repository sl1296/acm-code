
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
int cas;
int n;
ll a[110000];
ll pre[110000];
int main()
{
    scanf("%d",&cas);
    int numcas=0;
    while(cas--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%lld",&a[i]);
        pre[0]=a[0];
        for(int i=1;i<n;i++)
            pre[i]=pre[i-1]^a[i];
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",++numcas);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int num=r-l+1;
            //printf("num=%d\n",num);
            if(l==r) printf("%lld\n",a[l]);
            else
            {
                if(num&1) printf("%lld\n",a[l]^a[r]);
                else printf("%lld\n",pre[r]^pre[l-1]);
            }
        }
    }
    return 0;
}


