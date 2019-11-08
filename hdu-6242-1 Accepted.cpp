
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<time.h>
#define ll long long
using namespace std;
#define eps 1e-5
inline double dis(double xo,double yo,double xa,double ya){
    return (xo-xa)*(xo-xa)+(yo-ya)*(yo-ya);
}
inline bool cal(double &r,double &xo,double &yo,double xa,double ya,double xb,double yb,double xc,double yc){
    if(fabs((ya-yc)*(xa-xb)-(ya-yb)*(xa-xc))<eps)return false;
    xo=((xa*xa-xb*xb+ya*ya-yb*yb)*(ya-yc)-(xa*xa-xc*xc+ya*ya-yc*yc)*(ya-yb))/(2*(ya-yc)*(xa-xb)-2*(ya-yb)*(xa-xc));
    yo=((xa*xa-xb*xb+ya*ya-yb*yb)*(xa-xc)-(xa*xa-xc*xc+ya*ya-yc*yc)*(xa-xb))/(2*(ya-yb)*(xa-xc)-2*(ya-yc)*(xa-xb));
    r=dis(xo,yo,xa,ya);
    return true;
}
double x[100010],y[100010];
int p[100010];
int n;
int main(){
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    srand(time(NULL));
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            scanf("%lf%lf",&x[i],&y[i]);
//            printf("%f\n",sqrt(dis(0, 0.5,x[i],y[i])));
        }
        if(n==1){
            printf("%.6f %.6f %.6f\n",x[0],y[0],0.0);
            continue;
        }else if(n<=4){
            printf("%.6f %.6f %.6f\n",(x[0]+x[1])/2,(y[0]+y[1])/2,sqrt(dis(x[0],y[0],x[1],y[1]))/2);
            continue;
        }
        int lea=(n+1)/2;
        for(int i=0;i<n;++i) p[i]=i;
        shuffle(p,p+n,default_random_engine(time(NULL)));
        int a,b,c,z=0;
        while(1){
            if(z+2>=n)
            {
                z=0;
                shuffle(p,p+n,default_random_engine(time(NULL)));
            }
            a=p[z++];b=p[z++];c=p[z++];
//            printf("%d %d %d\n",a,b,c);
            double aa,bb,r;
            if(cal(r,aa,bb,x[a],y[a],x[b],y[b],x[c],y[c])){
                int cnt=0;
                for(int i=0;i<n;++i){
                    if(fabs(dis(x[i],y[i],aa,bb)-r)<eps)++cnt;
                }
                if(cnt>=lea){
                    printf("%.6f %.6f %.6f\n",aa,bb,sqrt(r));
                    break;
                }
            }
        }
    }
    return 0;
}

