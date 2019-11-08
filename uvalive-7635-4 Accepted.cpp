
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dis[4510000];
int n,m;
int px[3100],py[3100];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++) scanf("%d%d",&px[i],&py[i]);
        int disnum=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
                dis[disnum++]=(px[i]-px[j])*(px[i]-px[j])+(py[i]-py[j])*(py[i]-py[j]);
        }
        sort(dis,dis+disnum);
        while(m--)
        {
            int r;
            scanf("%d",&r);
            int sum=0;
            r*=r;
            int pos=upper_bound(dis,dis+disnum,r)-dis;
            printf("%.2f\n",(double)(2*pos+n)/(double)n);
        }
        printf("\n");
    }
    return 0;
}


