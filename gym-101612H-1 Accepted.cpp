
#include <bits/stdc++.h>
using namespace std;
#define N 100010
vector<int> son[N],no_match[N];
int dp[N][2],to[N],fa[N];
int n;
void dfs1(int x)
{
    int sum=0,z=0,tmp;
    for(auto y:son[x])
    {
        dfs1(y);
        if(dp[y][0]>=dp[y][1])
        {
            sum+=dp[y][0];
            z=y;
        }
        else sum+=dp[y][1];
    }
    dp[x][0]=sum;
    if(z)
    {
        dp[x][1]=sum+1;to[x]=z;
    }
    else
    {
        for(auto y:son[x])
        {
            tmp=sum-dp[y][1]+dp[y][0]+1;
            if(dp[x][1]<tmp)
            {
                dp[x][1]=tmp;to[x]=y;
            }
        }
    }
}
void dfs2(int x,int flag,vector<int> &vec)
{
    if(flag)
    {
        for(auto y:son[x])
            dfs2(y,0,vec);
    }
    else
    {
        if(dp[x][0]>=dp[x][1])
        {
            vec.push_back(x);
            for(auto y:son[x])
                dfs2(y,0,vec);
        }
        else
        {
            for(auto y:son[x])
            {
                if(y==to[x]) dfs2(y,1,vec);
                else dfs2(y,0,vec);
            }
        }
    }
}
bool cmp(int x,int y)
{
    return no_match[x].size()>no_match[y].size();
}
int main()
{
    freopen("hidden.in","r",stdin);
    freopen("hidden.out","w",stdout);
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
    {
        scanf("%d",&fa[i]);
        son[fa[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;++i)
        if(fa[i]==0)
        {
            dfs1(i);
            dfs2(i,0,no_match[i]);
            ans+=max(dp[i][0],dp[i][1]);
        }
    vector<int> vec;
    for(int i=2;i<=n;++i)
        if(fa[i]==0)
        {
            if(dp[i][0]<dp[i][1])
            {
                fa[i]=1;
                for(auto x:no_match[i])
                    no_match[1].push_back(x);
            }
            else vec.push_back(i);
        }
    sort(vec.begin(),vec.end(),cmp);
    for(auto x:vec)
    {
        if(no_match[1].size()==0)
        {
            fa[x]=1;
            for(auto y:no_match[x])
                no_match[1].push_back(y);
        }
        else
        {
            fa[x]=no_match[1][no_match[1].size()-1];
            no_match[1].pop_back();
            ++ans;
            for(auto y:no_match[x])
                if(y!=x) no_match[1].push_back(y);
        }
    }
    printf("%d\n",ans);
    for(int i=2;i<=n;++i) printf("%d ",fa[i]);
    return 0;
}
/*
6
3 1 0 4 4

6
3 1 0 6 4
*/

