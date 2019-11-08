
#include <bits/stdc++.h>
using namespace std;
#define N 100010
set<int> se[N];
vector<int> g[N];
int v[N],ans[N],be[N];
int n,cnt;
int Merge(int x,int y,int num)
{
    if(se[x].size()>se[y].size())
        swap(x,y);
//    printf("%d %d %d %d !!\n",x,y,se[x].size(),se[y].size());
    for(int val:se[x])
    {
//        printf("%d ?\n",val);
        if(se[y].find(val)==se[y].end())
            se[y].insert(val);
        else
        {
            ans[num]=max(ans[num],val);
//            printf("find!!\n");
        }
    }
    return y;
}
void dfs(int x)
{
    int tmp,z=sqrt(v[x]);
    be[x]=++cnt;
    for(int i=1;i<=z;++i)
        if(v[x]%i==0)
        {
            se[be[x]].insert(i);
            tmp=v[x]/i;
            if(tmp!=i)
                se[be[x]].insert(tmp);
        }
//    printf("x %d %d \n",x,se[b[x]].size());
//    for(int val:se[b[x]]) printf("%d ",val);
//    printf("\n");
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        dfs(y);
//        printf("%d %d -----\n",x,y);
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

