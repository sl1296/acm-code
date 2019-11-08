
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int x[100010],y[100010];
int main(){
//    double a=((1e7*1e7+1)*2-(2e7*2e7))/2/(1e7*1e7+1);
//    double ang=2e7/sin(acos(a));
//    printf("%f\n",ang);
    int n;
    scanf("%d",&n);
    int zs=0,fs=0,lin=0,xzb,mx=-1e8,mi=1e8;
    for(int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
        if(y[i]<0)++fs;
        else if(y[i]>0)++zs;
        else ++lin,xzb=x[i];
    }
//    printf("%d %d %d %d\n",zs,fs,lin,xzb);
    if(zs && fs || lin>1){
        printf("-1\n");
    }else{
        if(fs){
            for(int i=0;i<n;++i)y[i]=-y[i];
        }
        double l=0.0,r=1e15,mid,h,ms,len,tmp;
        while((r-l)/max(1.0,l)>4e-7){
            mid=(l+r)/2.0;
//            printf("%f %f %f\n",l,r,mid);
            ms=mid*mid;
            double xl=-1e16,xr=1e16;
            if(lin)xl=xr=xzb;
            for(int i=0;i<n;++i){
                h=y[i]-mid;
                tmp=ms-h*h;
                if(tmp<0){
                    xl=1e16;
                    xr=-1e16;
                }else{
                    len=sqrt(tmp);
                    xl=max(xl,x[i]-len);
                    xr=min(xr,x[i]+len);
                }
            }
//            printf("%f %f\n",xl,xr);
            if(xl<=xr)r=mid;else l=mid;
        }
        printf("%.6f\n",l);
    }
    return 0;
}

