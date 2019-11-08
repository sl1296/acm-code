
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int mod=100000000;
int a[20];
int dp[15][4500];
using namespace std;
int main(){
    int x,y,i,j,k,e;
    while(scanf("%d%d",&x,&y)!=EOF){
        for(i=0;i<x;i++){
            a[i]=0;
            for(j=0;j<y;j++){
                scanf("%d",&e);
                a[i]+=e<<j;
            }
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        int mmax=1<<y;
        for(i=1;i<=x;i++){
            for(j=0;j<mmax;j++){
                if((a[i-1]&j)!=j || j&(j>>1) || j&(j<<1))continue;
                for(k=0;k<mmax;k++){
                    if(j&k)continue;
                    dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                }
            }
        }
        int ans=0;
        for(i=0;i<mmax;i++)ans=(ans+dp[x][i])%mod;
        printf("%d\n",ans);
    }
    return 0;
}

