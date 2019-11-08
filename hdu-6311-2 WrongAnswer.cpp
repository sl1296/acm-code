
/*
有50个点，m条边，找出欧拉回路。
先判断度，再判断所有度不为0的点是否联通，
然后用dfs2逆序输出欧拉回路
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define N 100010
int head[N],to[N*4],pre[N*4],id[N*4];
bool vis[N],f[N*4];//f[i]表示编号为i的边是否已被遍历
int n,m,e;
vector<vector<int> > ans;
vector<int> vec;
void addedge(int x,int y,int i)
{
    to[e]=y;pre[e]=head[x];id[e]=i;f[e]=true;head[x]=e++;
}
void dfs2(int x)//
{
    vis[x]=true;
    int y;
    for(int i=head[x];i!=-1;i=pre[i])
    {
        if(!f[i]) continue;
        f[i]=f[i^1]=false;
        y=to[i];
        dfs2(y);
        vec.push_back(id[i]);
//        printf("%d %d\n",y,x);
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        ans.clear();
        for(int i=1;i<=n;++i)
        {
            head[i]=-1;vis[i]=false;
        }
        e=0;
        int x,y;
        for(int i=1;i<=m;++i)
        {
            scanf("%d%d",&x,&y);
            addedge(x,y,i);addedge(y,x,-i);
            addedge(x,y,i);addedge(y,x,-i);
        }
        for(int i=1;i<=n;++i)
            if(!vis[i])
            {
                vec.clear();
                dfs2(i);
                if(vec.size()) ans.push_back(vec);
            }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();++i)
        {
            printf("%d",ans[i].size());
            for(int j=ans[i].size()-1;j>=0;--j)
                printf(" %d",ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}
/*
7 8
1 2
1 3
2 3
4 5
5 6
6 7
7 4
4 6

4 3
1 2
1 3
2 3

*/

