
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define N 100010
using namespace std;
int n;
int pa[N][18];
int fa[N];
int ch[N][2];
int rt[N];
int size[N];
int rev[N];
vector<int> g[N];
void init()
{
    for(int i=1;i<=n;i++)rt[i]=1,size[i]=1;
    memset(fa,0,sizeof(fa));
    memset(ch,0,sizeof(ch));
    memset(rev,0,sizeof(rev));
}
void pushup(int x)
{
    size[x]=size[ch[x][0]]+size[ch[x][1]]+1;
}
void rotate(int x)
{
    int y=fa[x],kind=ch[y][1]==x;
    ch[y][kind]=ch[x][!kind];
    fa[ch[x][!kind]]=y;
    ch[x][!kind]=y;
    fa[x]=fa[y],fa[y]=x;
    if(rt[y])
    {
        rt[y]=0,rt[x]=1;
    }else ch[fa[x]][ch[fa[x]][1]==y]=x;
    pushup(y);
}
void splay(int x)
{
    while(!rt[x])
    {
        int y=fa[x],z=fa[y];
        if(rt[y]) rotate(x);
        else
        {
            if((ch[y][1]==x)==(ch[z][1]==y))
            {
                rotate(y),rotate(x);
            }else rotate(x),rotate(x);
        }
    }
    pushup(x);
}
void access(int x)
{
    int y=0;
    while(x)
    {
        splay(x);
        rt[ch[x][1]]=1,rt[y]=0;
        ch[x][1]=y;
        pushup(x);
        y=x,x=fa[x];
    }
}
void mt(int x)
{
    access(x);
    splay(x);
}
void link(int x,int y)
{
    mt(x);
    fa[ch[x][0]]=0;
    rt[ch[x][0]]=1;
    ch[x][0]=0;
    fa[x]=y;
    pushup(x);
}
void dfs(int x,int p)
{
    pa[x][0]=p;
    for(int i=1;i<18;++i)
        pa[x][i]=pa[pa[x][i-1]][i-1];
    for(int i=0;i<g[x].size();++i)
    {
        int y=g[x][i];
        if(y==p) continue;
        dfs(y,x);
    }
}
int father(int x,int h)
{
    for(int i=0;i<18;++i)
        if((h>>i)&1) x=pa[x][i];
    return x;
}
int main()
{
    int ca,x,y,z;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;++i) g[i].clear();
        for(int i=2;i<=n;++i)
        {
            scanf("%d",&x);
            g[x].push_back(i);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&z);
            x=father(i,z);
            if(x) link(i,x);
        }
        int m;
        scanf("%d",&m);
        while(m--)
        {
            int jd;
            scanf("%d",&jd);
            switch(jd)
            {
                int x,y;
                case 1:scanf("%d",&x);x;mt(x);printf("%d\n",size[ch[x][0]]+1);break;
                case 2:scanf("%d%d",&x,&z);x;y=father(x,z);if(y==0)link(x,0);else link(x,y);break;
            }
        }
    }
    return 0;
}
/*
2
4
1 2 3
1 1 1 1
3
1 4
2 3 2
1 4
6
1 1 2 2 4
1 1 1 1 1 1
10
1 4
1 5
2 4 2
1 4
1 5
*/

