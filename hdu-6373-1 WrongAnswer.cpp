
#include <bits/stdc++.h>
using namespace std;
const double PI=acos(-1);
const double g=9.8;
double a,b,a1,a2,v,x,y;
void solve()
{
    double a3=a2-a1-a1;
    double vx=v*cos(a3),vy=v*sin(a3);
    double t=(2*vx*b+2*a*vy)/(a*g);
    x-=vx*t;y-=-vy*t+g*t*t/2;
    vy=-vy+g*t;
    double v=sqrt(vx*vx+vy*vy);
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&x,&y);
        a1=atan(b/a);x=-x;
        double h=y-b*x/a;
        double t=sqrt(2*h/g);
        v=g*t;y=b*x/a;a2=PI/2;
        int cnt=0;
        while(y>0)
        {
            ++cnt;
            solve();
        }
        printf("%d\n",cnt);
    }
    return 0;
}

