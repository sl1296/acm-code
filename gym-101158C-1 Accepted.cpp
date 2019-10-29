
#include <bits/stdc++.h>
using namespace std;
#define N 200010
typedef pair<int,int> pii;
pii a[N];
int l[N],r[N];
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+m+1);
    for(int i=1;i<=n;++i) l[i]=r[i]=i;
    for(int i=1;i<=m;++i)
    {
        int y=a[i].second;
        int L=min(l[y],l[y+1]);
        int R=max(r[y],r[y+1]);
        l[y]=l[y+1]=L;r[y]=r[y+1]=R;
//        printf("%d %d %d %d %d ?\n",y,l[y],r[y],l[y+1],r[y+1]);
    }
    for(int i=1;i<=n;++i)
        printf("%d ",r[i]-l[i]+1);
    return 0;
}

