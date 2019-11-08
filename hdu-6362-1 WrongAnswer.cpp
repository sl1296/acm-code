
#include <bits/stdc++.h>
using namespace std;
double a,b;
double f(double y)
{
    double t=y/b;
    return (4*a*b*(t*sqrt(1-t*t)/2+asin(t)/2)+2*y*y)/b;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%lf%lf",&a,&b);
        printf("%.6f\n",f(b)-f(0));
    }
    return 0;
}

