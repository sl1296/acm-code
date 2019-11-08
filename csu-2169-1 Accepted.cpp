
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1049000];
int main(){
//    freopen("01.in","r",stdin);
//    freopen("01+.out","w",stdout);
    int n,m,a[50],b[50];
    while(~scanf("%d%d",&n,&m)){
        memset(b,0,sizeof(b));
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0,x,y;i<m;++i){
            scanf("%d%d",&x,&y);x--;y--;
            b[x]|=(1<<y);
            b[y]|=(1<<x);
        }
//        for(int i=0;i<n;++i)printf("%d ",b[i]);printf("\n");
        for(int i=1;i<(1<<n);++i)dp[i]=1LL<<61;
        for(int i=0;i<(1<<n);++i){
            int x=__builtin_popcount(i);
            for(int j=0;j<n;++j){
                if((i&(1<<j))==0){
                    dp[i|(1<<j)]=min(dp[i|(1<<j)],dp[i]+(ll)a[x]*(__builtin_popcount(b[j]&i)-__builtin_popcount(b[j]&(~i))));
//                    printf("%lld\n",dp[i|(1<<j)]);
                }
            }
        }
        printf("%lld\n",dp[(1<<n)-1]);
    }
    return 0;
}

