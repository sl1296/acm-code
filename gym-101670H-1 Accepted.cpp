
#include <bits/stdc++.h>
using namespace std;
#define N 200010
int a[N],fa[N];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            fa[a[i]]=i;
        }
        int cnt=0;
        for(int i=1;i<=n;++i)
            if(fa[i]!=i)
            {
                int x=i,y=fa[i];
                swap(a[x],a[y]);
                fa[a[x]]=x;fa[a[y]]=y;
                ++cnt;
            }
        printf("%d\n",cnt);
    }
    return 0;
}

