
#include <bits/stdc++.h>
using namespace std;
#define N 200010
int nxt[N],pre[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    pre[0]=-1;nxt[0]=1;
    for(int i=1;i<=n;++i)
    {
        pre[i]=i-1;nxt[i]=i+1;
    }
    pre[n+1]=n;nxt[n+1]=-1;
    int x;
    while(m--)
    {
        scanf("%d",&x);
        nxt[pre[x]]=nxt[x];
        pre[nxt[x]]=pre[x];
        pre[x]=0;pre[nxt[0]]=x;
        nxt[x]=nxt[0];nxt[0]=x;
    }
    x=0;
    while(nxt[x]<=n)
    {
        printf("%d\n",nxt[x]);
        x=nxt[x];
    }
    return 0;
}
/*
5 3
4
2
5
*/

