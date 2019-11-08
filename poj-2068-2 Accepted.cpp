
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dp[22][8200],n,s,a[22];
int ca(int num,int r){
    int i;
    if(dp[num][r]!=-1)return dp[num][r];
    if(r==0)return dp[num][r]=1;
    dp[num][r]=0;
    for(i=1;(i<=a[num] && i<=r);i++)if(!ca((num+1)%(2*n),r-i))dp[num][r]=1;
    return dp[num][r];
}
int main(){
    int i;
    while(1){
        scanf("%d",&n);
        if(!n)break;
        scanf("%d",&s);
        for(i=0;i<2*n;i++)scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",ca(0,s));
    }
    return 0;
}

