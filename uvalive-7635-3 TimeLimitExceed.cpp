
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dis[3100][3100];
inline int get_dis(const int& x1,const int& y1,const int& x2,const int& y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int n,m;
int px[3100],py[3100];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++) scanf("%d%d",&px[i],&py[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                dis[i][j]=get_dis(px[i],py[i],px[j],py[j]);
            sort(dis[i],dis[i]+n);
        }
        while(m--)
        {
            int r;
            scanf("%d",&r);
            int sum=0;
            r*=r;
            for(int i=0;i<n;i++)
                sum+=upper_bound(dis[i],dis[i]+n,r)-dis[i];
            printf("%.2f\n",(double)sum/n);
        }
        printf("\n");
    }
    return 0;
}


