
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define eps 1e-6
double p[25],dp[1100000],ans[25];
int main(){
    int n,k,i,j,all,c;
    double l;
    scanf("%d%d",&n,&k);
    all=0;
    for(i=0;i<n;i++){
        scanf("%lf",&p[i]);
        if(p[i]<eps)all++;
    }
    k=k>n-all?n-all:k;
    dp[0]=1;
    all=1<<n;
    for(i=0;i<all;i++){
        l=1;
        c=0;
        for(j=0;j<n;j++)if(i&(1<<j))c++;
        for(j=0;j<n;j++){
            if(i&(1<<j)){
                l-=p[j];
                if(c==k)ans[j]+=dp[i];
            }
        }
        for(j=0;j<n;j++){
            if(i&(1<<j))continue;
            dp[i|(1<<j)]+=dp[i]*p[j]/l;
        }
    }
    for(i=0;i<n;i++){
        if(i)printf(" ");
        printf("%.7f",ans[i]);
    }
    printf("\n");
    return 0;
}

