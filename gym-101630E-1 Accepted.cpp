
#include <bits/stdc++.h>
using namespace std;
#define N 1010
int a[N],num[N];
int n;
int main()
{
    scanf("%d",&n);
    int tmp=0;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    bool flag=true;
    vector<int> ans;
    for(int i=1;i<=n;++i)
    {
        if(a[i]>0) ++num[a[i]];
        else if(a[i]==0) ++tmp;
        else
        {
            if(num[-a[i]]) --num[-a[i]];
            else if(tmp)
            {
                --tmp;
                ans.push_back(-a[i]);
            }
            else
            {
                flag=false;break;
            }
        }
    }
    if(flag)
    {
        puts("Yes");
        for(int i=1;i<=tmp;++i) ans.push_back(1);
        for(auto x:ans) printf("%d ",x);
    }
    else puts("No");
    return 0;
}
/*
10
1 0 -4 0 0 -1 -3 0 -1 -2

5
5 8 0 0 -3

3
2 -2 -2
*/

