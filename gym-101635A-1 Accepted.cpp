
#include <bits/stdc++.h>
using namespace std;
#define N 2010
int n,m;
int a[N],b[N];
map<int,int> mp;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    for(int i=1;i<=m;++i) scanf("%d",&b[i]);
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n&&a[j]<=b[i];++j)
            mp[b[i]-a[j]]++;
    int ans,mx=0;
    for(auto p:mp)
        if(p.second>mx)
        {
            mx=p.second;
            ans=p.first;
        }
        else ans=min(ans,p.first);
    printf("%d\n",ans);
    return 0;
}
/*
5 5
0 10 12 20 30
1 5 17 27 50
*/

