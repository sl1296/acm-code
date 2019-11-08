
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
double dis[9100000];
double get_dis(double x1,double y1,double x2,double y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int n,m;
double px[3100],py[3100];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++) scanf("%lf%lf",&px[i],&py[i]);
        int disnum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[disnum++]=get_dis(px[i],py[i],px[j],py[j]);
        sort(dis,dis+disnum);
      //  for(int i=0;i<disnum;i++) printf("dis[%d]=%f\n",i,dis[i]);
        while(m--)
        {
            double r;
            scanf("%lf",&r);
            int sum=0;
            r=r*r;
            int pos=upper_bound(dis,dis+disnum,r)-dis;
           // printf("pos=%d\n",pos);
            printf("%.2f\n",(double)pos/(double)n);
        }
        printf("\n");
    }
    return 0;
}


