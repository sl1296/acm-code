
#include <bits/stdc++.h>
using namespace std;
#define N 110
typedef pair<int,int> pii;
int n;
const double pi=acosl(-1.0);
const double eps=1e-6;
double area(double x,double y,double r,double xx,double yy,double rr)
{
    if(r>rr) swap(r,rr);
    double d=sqrtl((x-xx)*(x-xx)+(y-yy)*(y-yy));
    if(d>=r+rr) return 0;
    if(d<=rr-r) return pi*r*r;
    double k=acosl((r*r+d*d-rr*rr)/(d*r*2));
    double kk=acosl((rr*rr+d*d-r*r)/(d*rr*2));
    return r*r*k+rr*rr*kk-sinl(k)*(r*r+d*d-rr*rr)/(2*d)*r-sinl(kk)*(rr*rr+d*d-r*r)/(2*d)*rr;
}
int main()
{
    int ca;
    scanf("%d",&ca);
    while(ca--)
    {
        double R,r;
        scanf("%d%lf%lf",&n,&R,&r);
        double x,y;
        vector<pii> vec;
        for(int i=1;i<=n;++i)
        {
            scanf("%lf%lf",&x,&y);
            vec.push_back(make_pair(area(0,0,R-r,x,y,r),i));
        }
        sort(vec.begin(),vec.end(),greater<pii>());
        vector<int> ans;
        ans.push_back(vec[0].second);
        for(int i=1;i<vec.size();++i)
            if(fabs(vec[i].first-vec[i-1].first)<eps)
                ans.push_back(vec[i].second);
            else break;
        sort(ans.begin(),ans.end());
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();++i)
        {
            printf("%d",ans[i]);
            if(i==ans.size()-1) printf("\n");
            else printf(" ");
        }
    }
    return 0;
}

