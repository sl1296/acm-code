
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node{
    double l,r;
    bool operator < (const node &p) const{
        if(r!=p.r)return r<p.r;
        return l>p.l;
    }
};
node a[1010];
int main(){
  //  system("chcp 936");
    int n,cas=1;
    double d;
    while(1){
        scanf("%d%lf",&n,&d);
        if(n==0&&d==0)break;
        bool is=true;
        for(int i=0;i<n;i++){
            double u,v;
            scanf("%lf%lf",&u,&v);
            if(v>d)is=false;
            double ad=sqrt(d*d-v*v);
            a[i].l=u-ad;
            a[i].r=u+ad;
        }
        printf("Case %d: ",cas++);
        if(is==false){
            printf("-1\n");
            continue;
        }
        sort(a,a+n);
        int ans=0;
        double en=-1e10;
        for(int i=0;i<n;i++){
            if(a[i].l>en){
                en=a[i].r;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

