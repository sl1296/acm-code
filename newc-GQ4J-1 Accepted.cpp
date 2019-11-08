
#include <bits/stdc++.h>
using namespace std;
#define N 1010
string st[N];
int a[N];
bool f[N];
int n,m;
int main()
{
    memset(f,1,sizeof(f));
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>a[i]>>st[i];
        if(i==1) f[a[i]]=0;
        if(i>1&&st[i]!=st[i-1])
            f[a[i]]=false;
    }
    for(int i=1;i<=n;++i)
        if(f[i]) cout<<i<<' ';
    return 0;
}
/*
3 5
1 gugugu
2 gugugu
1 gugugu
3 tingzhifudu
2 tingzhifudu
*/

