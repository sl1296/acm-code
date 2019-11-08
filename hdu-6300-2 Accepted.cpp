
#include <bits/stdc++.h>
using namespace std;
#define N 100010
struct Point{
    int x,y,id;
}P[N];
int n;
bool cmp(Point &a,Point &b)
{
    return a.y<b.y||a.y==b.y&&a.x<b.x;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%d",&n);
        for(int i=1;i<=3*n;++i)
        {
            scanf("%d%d",&P[i].x,&P[i].y);
            P[i].id=i;
        }
        sort(P+1,P+3*n+1,cmp);
        for(int i=1;i<=3*n;i+=3)
            printf("%d %d %d\n",P[i].id,P[i+1].id,P[i+2].id);
    }
    return 0;
}

