
#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
#define N 30010
#define M 200010
int n,m,k;
bool dp[N];
char st[M];
int a[30];
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d%d%d",&n,&m,&k);
        scanf("%s",st);
        memset(a,0,sizeof(a));
        for(int i=0;i<k;++i)
            ++a[st[i]-'A'];
        sort(a,a+26,greater<int>());
        for(int i=1;i<=n;++i) dp[i]=false;
        dp[0]=true;
        int d=k-n-m,ans=inf;
        for(int i=0;i<26;++i)
            if(a[i])
            {
                for(int j=max(0,n-a[i]);j<=n;++j)
                    if(dp[j])
                    {
                        int tmp=a[i]-(n-j);
                        if(tmp<=d) ans=0;
                        else ans=min(ans,(n-j)*(tmp-d));
                    }
                for(int j=n;j>=a[i];--j)
                    dp[j]|=dp[j-a[i]];
            }
        for(int i=1;i<=m;++i) dp[i]=false;
        dp[0]=true;
        for(int i=0;i<26;++i)
            if(a[i])
            {
                for(int j=max(0,m-a[i]);j<=m;++j)
                    if(dp[j])
                    {
                        int tmp=a[i]-(m-j);
                        if(tmp<=d) ans=0;
                        else ans=min(ans,(m-j)*(tmp-d));
                    }
                for(int j=m;j>=a[i];--j)
                    dp[j]|=dp[j-a[i]];
            }
        printf("%d\n",ans);
    }
    return 0;
}

