
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int m,n,sx,sy,ex,ey;
    double r;
    while(~scanf("%d%d%lf%d%d%d%d",&m,&n,&r,&sx,&sy,&ex,&ey)){
        double rr=r/n;
        double arg=3.1415926535897932/m;
        double ans=rr*(sy+ey);
        for(int i=0;i<=n;++i){
            double now=(fabs(i-sy)+fabs(i-ey))*rr+fabs(ex-sx)*i*rr*arg;
//            printf("%f %f %f\n",fabs(i-sy)+fabs(i-ey),fabs(ex-sx),now);
            ans=min(ans,now);
        }
        printf("%.8f\n",ans);
    }
    return 0;
}

