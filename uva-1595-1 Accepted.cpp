
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
struct node{
    double x,y;
    bool operator < (const node &p) const{
        if(x!=p.x)return x<p.x;
        return y<p.y;
    }
};
node a[1010];
const int INF=2147483600;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<node,int> ma;
        double ll=INF,rr=-INF;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&a[i].x,&a[i].y);
            ma[a[i]]=1;
            ll=min(ll,a[i].x);
            rr=max(rr,a[i].x);
        }
        double mid=(ll+rr)/2;
        bool ans=true;
        for(int i=0;i<n;i++){
            if(ma[(node){2*mid-a[i].x,a[i].y}]==0){
                ans=false;
                break;
            }
        }
        if(ans){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}

