
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll __int64
ll a,b,n;
ll z[1000100];
ll min=1e9,re;
int zs[500],zsn,fx[500],fxn;
ll cost[1000010],dp[1000010][3];
int cmp(const void *a,const void *b){
    return *(int*)a-*(int*)b;
}
ll solve(int x){
    ll r;
    int i;
    for(i=1;i<=n;i++){
        cost[i]=1e12+7;
        if(z[i]%x==0)cost[i]=0;
        else if((z[i]+1)%x==0 || (z[i]-1)%x==0)cost[i]=b;
    }
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+cost[i];
        dp[i][1]=((dp[i-1][0]>dp[i-1][1])?dp[i-1][1]:dp[i-1][0])+a;
        dp[i][2]=((dp[i-1][1]>dp[i-1][2])?dp[i-1][2]:dp[i-1][1])+cost[i];
    }
    r=dp[n][2]>dp[n][1]?dp[n][1]:dp[n][2];
    r=r>dp[n][0]?dp[n][0]:r;
   // printf("%I64d %I64d %I64d\n",dp[n][0],dp[n][1],dp[n][2]);
    return r;
}
void pr(int x){
    int i;
    for(i=2;i*i<=x;i++){
        if(x%i==0){
           // printf("%d %d %d\n",x,i,zsn);
            zs[zsn]=i;
            x/=i;
            while(x%i==0)x/=i;
            zsn++;
        }
    }
    if(x>1){
   //     printf("%d %d %d\n\n",x,zsn,1);
        zs[zsn]=x;
        zsn++;
    }
}
int main(){
    int i;
    scanf("%I64d%I64d%I64d",&n,&a,&b);
    for(i=1;i<=n;i++)scanf("%I64d",&z[i]);
    pr(z[1]);
    pr(z[1]+1);
    pr(z[1]-1);
    pr(z[n]);
    pr(z[n]+1);
    pr(z[n]-1);
    qsort(zs,zsn,sizeof(int),*cmp);
    for(i=0;i<zsn;i++){
    //    printf("%d %d\n",i,zs[i]);
        while(i+1<zsn && zs[i+1]==zs[i])i++;
        fx[fxn]=zs[i];
        fxn++;
    }
  //  printf("%d\n",fxn);
    for(i=0;i<fxn;i++){
        re=solve(fx[i]);
     //   printf("%d %I64d %I64d\n",fx[i],min,re);
        if(min>re)min=re;
    }
    printf("%I64d\n",min);
    return 0;
}

