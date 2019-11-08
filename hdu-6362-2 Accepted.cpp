
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        double ans=f(b)-f(0);
        ll tmp=(ll)(ans*1000000);
        printf("%.6f\n",tmp/1000000.0);
    }
    return 0;
}

