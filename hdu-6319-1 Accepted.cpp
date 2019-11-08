
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000010
int c[N],pre[N],id[N];
ll a[N],que[N];
int n,m;
int main()
{
    int ca,k;
    ll p,q,r,mod;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d%lld%lld%lld%lld",&n,&m,&k,&p,&q,&r,&mod);
        c[0]=0;
        for(int i=1;i<=k;++i)
        {
            scanf("%d",&a[i]);
            c[i]=0;
        }
        for(int i=k+1;i<=n;++i)
        {
            a[i]=(p*a[i-1]+q*i+r)%mod;
            c[i]=0;
        }
        int s=1,t=1;que[1]=a[1];id[1]=1;pre[1]=0;
        for(int i=2;i<=n;++i)
        {
            while(s<=t&&que[t]<a[i]) --t;
            if(s>t) pre[i]=0;
            else pre[i]=id[t];
            que[++t]=a[i];id[t]=i;
        }
        s=1;t=0;
        for(int i=1;i<=m;++i)
        {
            while(s<=t&&que[t]<a[i]) --t;
            que[++t]=a[i];id[t]=i;
            ++c[pre[i]];
        }
//        for(int i=1;i<=n;++i) printf("%d ",pre[i]);
//        printf("\n");
        ll A=que[s]^1,B,tmp=c[0];
        if(a[1]==0) B=(tmp-1)^1;
        else B=tmp^1;
//        printf("%d %d ?\n",1,tmp);
        for(int i=m+1;i<=n;++i)
        {
            if(pre[i-m]<i-m) --tmp;
            ++c[pre[i]];
            if(pre[i]<i-m) ++tmp;
            tmp+=c[i-m];
            while(s<=t&&i-id[s]>=m) ++s;
            while(s<=t&&que[t]<a[i]) --t;
            que[++t]=a[i];id[t]=i;
            A+=que[s]^(i-m+1);
            if(a[i-m+1]==0) B+=(tmp-1)^(i-m+1);
            else B+=tmp^(i-m+1);
//            printf("%d %d ?\n",i,tmp);
        }
        printf("%lld %lld\n",A,B);
    }
    return 0;
}
/*
3
10 6 10 5 5 5 5
3 2 2 1 5 7 6 8 2 9
10 3 5 7 7 7 7
5 2 6 4 7
5 3 5 5 5 5 5
2 3 0 1 0
*/

