
#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n;
int a[N],b[N];
vector<int> vec;
int solve()
{
    vector<int> v2;
    for(int x:vec)
    {
        auto it=lower_bound(v2.begin(),v2.end(),x);
        if(it==v2.end()) v2.push_back(x);
        else *it=x;
    }
    return v2.size();
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;++i)
            scanf("%d",&b[i]);
        vec.clear();
        for(int i=1;i<=n;++i)
            if(a[i]!=-1) vec.push_back(b[i]);
        int len=solve();
        if(len+1>=vec.size()) puts("#laughing_arjun");
        else puts("#itsnot_arjun");
    }
    return 0;
}

