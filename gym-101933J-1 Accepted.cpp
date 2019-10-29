
#include <bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
ll a,b,c,d;
ll calc(ll x)
{
    if(x==1) return 2;
    for(ll i=3;i<=x;++i)
    {
        if(i*(i-1)/2==x) return i;
        if(i*(i-1)/2>x) break;
    }
    return 0;
}
int arr[N];
int que[N];
void solve(int n,int m,int b,int c)
{
    int l=1,r=0;
    for(int i=1;i<=n;++i)
    {
        arr[i]=0;
        que[++r]=i;
    }
    for(int i=n+1;i<=n+m;++i)
    {
        arr[i]=1;
        while(r-l+1>c) ++l;
        if(c)
        {
            swap(arr[i],arr[que[l++]]);
            que[++r]=i;c-=r-l+1;
        }
    }
    for(int i=1;i<=n+m;++i) cout<<arr[i];
}
int main()
{
    cin>>a>>b>>c>>d;
    ll n,m;
    if(a==0&&d==0)
    {
        if(b==0&&c==0) puts("0");
        else if(b==1&&c==0) puts("01");
        else if(b==0&&c==1) puts("10");
        else puts("impossible");
    }
    else if(a==0)
    {
        m=calc(d);
        if(m==0) puts("impossible");
        else if(b==0&&c==0)
        {
            for(int i=1;i<=m;++i) cout<<1;
        }
        else if(b+c==m) solve(1,m,b,c);
        else puts("impossible");
    }
    else if(d==0)
    {
        n=calc(a);
        if(n==0) puts("impossible");
        else if(b==0&&c==0)
        {
            for(int i=1;i<=n;++i) cout<<0;
        }
        else if(b+c==n) solve(n,1,b,c);
        else puts("impossible");
    }
    else
    {
        ll n=calc(a),m=calc(d);
        if(n==0||m==0||b+c!=n*m) puts("impossible");
        else solve(n,m,b,c);
    }
    return 0;
}
/*
3 0 3 0
10
*/

