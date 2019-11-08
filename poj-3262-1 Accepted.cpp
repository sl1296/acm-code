
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    int t,d;
    bool operator < (const node &p) const{
        return 1.0*t/d<1.0*p.t/p.d;
    }
};
node a[100010];
int main(){
   // system("chcp 936");
    int n;
    while(~scanf("%d",&n)){
        ll ans=0,sum=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].t,&a[i].d);
            sum+=a[i].d;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            sum-=a[i].d;
            ans+=sum*a[i].t*2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

