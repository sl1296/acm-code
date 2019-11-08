
#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll a,b,c,d,e,f,g,h;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&e,&f,&g,&h);
        ll xs=max(a,e),xe=min(a+c,e+g),ys=max(b,f),ye=min(b+d,f+h);
//        printf("%lld %lld %lld %lld\n",xs,xe,ys,ye);
        ll xl=max(0LL,xe-xs),yl=max(0LL,ye-ys);
//        printf("%lld %lld\n",xl,yl);
        ll fz=xl*yl,fm=c*d+g*h-fz;
//        printf("%lld %lld\n",fz,fm);
        double ans=(double)fz/fm;
        printf("%.2f\n",ans);
    }
    return 0;
}

