
#include<cstdio>
int dp[3][50],z[50],r[50];
int main(){
    int n,i;
    dp[0][2]=2;dp[1][2]=dp[2][2]=1;z[2]=4;
    for(i=3;i<31;i++){
        z[i]=z[i-1]*2;
        dp[0][i]=dp[0][i-1]+dp[1][i-1]+dp[2][i-1];
        dp[1][i]=dp[0][i-1];
        dp[2][i]=dp[1][i-1];
        r[i]=z[i]-dp[0][i]-dp[1][i]-dp[2][i];
    }
    while(1){
        scanf("%d",&n);
        if(!n)break;
        printf("%d\n",r[n]);
    }
    return 0;
}

