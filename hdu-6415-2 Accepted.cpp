
#include<cstdio>
#define ll long long
ll dp[2][85][85];
ll ka[85][85],kb[85][85],kc[85][85],kd[85][85];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll n,m,mod;
        scanf("%lld%lld%lld",&n,&m,&mod);
        for(int i=0;i<85;++i)for(int j=0;j<85;++j)dp[1][i][j]=0;
        int all=n*m;
        dp[1][1][1]=all%mod;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                ka[i][j]=i*j;
                kb[i][j]=(n-i)*j;
                kc[i][j]=(m-j)*i;
            }
        }
        for(int i=2;i<=all;++i){
            for(int x=(i+m-2)/m;x<=n;++x)for(int y=(i+x-2)/x;y<=m;++y)dp[i&1][x][y]=0;
            for(int j=(i+m-2)/m;j<=n;++j){
                for(int k=(i+j-2)/j;k<=m;++k){
                    //j*m+k*n-j*k
                    //j*k
                    if(i-1<ka[j][k]){
                        dp[i&1][j][k]+=dp[(i+1)&1][j][k]*(ka[j][k]-i+1)%mod;
                        if(dp[i&1][j][k]>=mod)dp[i&1][j][k]-=mod;
                    }
                    if(j<n){
                        dp[i&1][j+1][k]+=dp[(i+1)&1][j][k]*kb[j][k]%mod;
                        if(dp[i&1][j+1][k]>=mod)dp[i&1][j+1][k]-=mod;
                    }
                    if(k<m){
                        dp[i&1][j][k+1]+=dp[(i+1)&1][j][k]*kc[j][k]%mod;
                        if(dp[i&1][j][k+1]>=mod)dp[i&1][j][k+1]-=mod;
                    }
                }
            }
//            for(int x=1;x<=n;++x){
//                for(int y=1;y<=m;++y){
//                    printf("%lld ",dp[i&1][x][y]);
//                }
//                printf("\n");
//            }
        }
        printf("%lld\n",dp[all&1][n][m]);
    }
    return 0;
}

