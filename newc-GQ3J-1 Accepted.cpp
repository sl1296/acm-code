
#include <bits/stdc++.h>
using namespace std;
#define N 300010
vector<int> g[N];
int color[N],pre[N];
int n,m,z1,z2;
void dfs(int x,int c)
{
    if(z1) return;
    color[x]=c;
    for(auto y:g[x])
    {
        if(color[y]==-1)
        {
            pre[y]=x;
            dfs(y,c^1);
        }
        else if(color[x]==color[y])
        {
            z1=x;z2=y;return;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(color,-1,sizeof(color));
    dfs(1,0);
    if(z1==0)
    {
        puts("0");
        for(int i=1;i<=n;++i)
            printf("%d ",color[i]);
    }
    else
    {
        vector<int> vec1,vec2;
        x=z1;
        while(x&&x!=z2)
        {
            vec1.push_back(x);
            x=pre[x];
        }
        if(x)
        {
            printf("%d\n",vec1.size()+1);
            printf("%d ",x);
            for(auto x:vec1) printf("%d ",x);
            return 0;
        }
        x=z2;
        while(x&&x!=z1)
        {
            vec2.push_back(x);
            x=pre[x];
        }
        if(x)
        {
            printf("%d\n",vec2.size()+1);
            printf("%d ",x);
            for(auto x:vec2) printf("%d ",x);
            return 0;
        }
        vec1.pop_back();
        printf("%d\n",vec1.size()+vec2.size());
        for(auto x:vec1) printf("%d ",x);
        reverse(vec2.begin(),vec2.end());
        for(auto x:vec2) printf("%d ",x);
    }
    return 0;
}
/*
3 3
1 2
1 3
2 3
*/

