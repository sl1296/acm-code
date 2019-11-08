
#include <stdio.h>
int a[110];
double p[110];
double dp[10010];
int main(){
    int t,n,i,sum,j;
    double lim;
    scanf("%d",&t);
    while(t--){
        sum=0;
        scanf("%lf%d",&lim,&n);
        for(i=0;i<n;i++){
            scanf("%d%lf",&a[i],&p[i]);
            sum+=a[i];
        }
        dp[0]=1;
        for(i=1;i<=sum;i++)dp[i]=-100;
        for(i=0;i<n;i++)for(j=sum;j>=a[i];j--){
            dp[j]=(dp[j]>(dp[j-a[i]]*(1-p[i])))?dp[j]:(dp[j-a[i]]*(1-p[i]));
        }
        for(i=sum;i>-1;i--)if(dp[i]<2 && dp[i]>=1-lim)break;
        if(i>-1)printf("%d\n",i); else printf("0\n");
    }
    return 0;
}

