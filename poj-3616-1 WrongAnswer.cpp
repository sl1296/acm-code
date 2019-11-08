
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
    int l,r,v;
    bool operator < (const node &p) const{
        return r<p.r;
    }
};
node a[1010];
int dp[1000010];
int main(){
    int n,m,r;
    while(~scanf("%d%d%d",&n,&m,&r)){
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].v);
        }
        sort(a,a+m);
        int p=0;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            while(p<m&&a[p].r==i){
                dp[i]=max(dp[i],dp[a[p].l-r-1]+a[p].v);
                p++;
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}

