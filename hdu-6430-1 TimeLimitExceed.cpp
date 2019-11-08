
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct rec{
    vector<int> vec;
    set<int> se;
}a[N];
vector<int> g[N];
int v[N],ans[N],be[N],b[N];
int n,cnt;
int Merge(int x,int y,int num)
{
    if(a[x].vec.size()>a[y].vec.size())
        swap(x,y);
    int t=0,z,val,tmp;
    set<int> &se=a[y].se;
    for(int i=0;i<a[x].vec.size();++i)
    {
        val=a[x].vec[i];
        z=sqrt(val);
        for(int j=1;j<=z;++j)
            if(val%j==0)
            {
                b[++t]=j;
                if(se.find(j)!=se.end())
                    ans[num]=max(ans[num],j);
                tmp=val/j;
                if(j==tmp) continue;
                b[++t]=tmp;
                if(se.find(tmp)!=se.end())
                    ans[num]=max(ans[num],tmp);
            }
        a[y].vec.push_back(val);
    }
    for(int i=1;i<=t;++i)
        se.insert(b[i]);
    return y;
}
void dfs(int x)
{
    int tmp,z=sqrt(v[x]);
    be[x]=++cnt;
    for(int i=1;i<=z;++i)
        if(v[x]%i==0)
        {
            a[be[x]].se.insert(i);
            tmp=v[x]/i;
            if(tmp!=i)
                a[be[x]].se.insert(i);
        }
    a[be[x]].vec.push_back(v[x]);
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        dfs(y);
        be[x]=Merge(be[x],be[y],x);
    }
}
int main()
{
    scanf("%d",&n);
    int x;
    for(int i=2;i<=n;++i)
    {
        scanf("%d",&x);
        g[x].push_back(i);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&v[i]);
        ans[i]=-1;
    }
    dfs(1);
    for(int i=1;i<=n;++i)
        printf("%d\n",ans[i]);
    return 0;
}


