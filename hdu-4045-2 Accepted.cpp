
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1000000007;
ll c[2001][2001]={1},stir2[1005][1005]={1};
int main(){
    int i,j;
    for(i=1;i<=2000;i++){
        c[i][0]=c[i][i]=1;
        for(j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
    }
    for(i=1;i<=1000;i++){
        stir2[i][0]=0;
        stir2[i][i]=1;
        for(int j=1;j<i;j++)stir2[i][j]=(j*stir2[i-1][j]+stir2[i-1][j-1])%mod;
    }
    int n,r,k,m;
    while(~scanf("%d%d%d%d",&n,&r,&k,&m)){
        ll sum=0;
        if(n-((r-1)*k+1)<0){
            printf("0\n");
            continue;
        }
        for(int i=1;i<=min(r,m);i++)sum=(sum+stir2[r][i])%mod;
        printf("%lld\n",(c[n-((r-1)*k+1)+r+1-1][r]*sum)%mod);
    }
    return 0;
}

