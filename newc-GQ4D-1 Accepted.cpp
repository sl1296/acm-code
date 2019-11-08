
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100010
int n;
int a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",&a[i]);
    priority_queue<int,vector<int>,greater<int> > q1,q2;
    q1.push(a[1]);
    for(int i=2;i<=n;++i)
        q2.push(a[i]);
    ll ans=0;
    while(!q2.empty())
    {
        ans+=q1.top()+q2.top();
        q1.push(q2.top());
        q2.pop();
    }
    printf("%lld\n",ans);
    return 0;
}

