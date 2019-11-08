
#include <bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
inline double dis2(double x,double y)
{
    return x*x+y*y;
}
double solve(double R,double x,double y,double r)
{
    double d2=dis2(x,y),d=sqrt(d2);
    if(d>R+r||d<R-r) return 0;
    double a=2*acos((d2+r*r-R*R)/(2*d*r));
    double b=2*acos((d2+R*R-r*r)/(2*d*R));
    return a*r-b*R;
}
int main()
{
    int ca,m;
    scanf("%d",&ca);
    double R,x,y,r;
    while(ca--)
    {
        scanf("%d%lf",&m,&R);
        double c=2*PI*R;
        for(int i=1;i<=m;++i)
        {
            scanf("%lf%lf%lf",&x,&y,&r);
            c+=solve(R,x,y,r);
        }
        printf("%.12f\n",c);
    }
    return 0;
}

