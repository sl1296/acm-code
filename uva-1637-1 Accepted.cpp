
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[11][6][4];
int is[1953130];
double dp[1953130];
int fi[11]={1,5,25,125,625,3125,15625,78125,390625};
double ans;
double dfs(int t){
   // printf("%d ",t);
    int a[10],l=t,count=0,i,j;
    if(!t)return 1.0;
    if(is[t])return dp[t];
    is[t]=1;
    for(i=0;i<9;i++){a[i]=l%5;l/=5;/*printf("%d ",a[i]);*/}//printf("\n");
    for(i=0;i<8;i++)for(j=i+1;j<9;j++)if(a[i] && a[j] && s[i][a[i]][0]==s[j][a[j]][0]){
    //    printf("%d %d %d %d %d\n",i,j,fi[i],fi[j],t-fi[i]-fi[j]);
        dp[t]+=dfs(t-fi[i]-fi[j]);count++;
    }
    if(count)dp[t]/=count;
    return dp[t];
}
int main(){
    int f[100][2],fc;
    int i,j;
    while(scanf("%s",s[0][1])!=EOF){
        memset(is,0,sizeof(is));
        memset(dp,0,sizeof(dp));
        fc=0;ans=0;
        scanf("%s%s%s",s[0][2],s[0][3],s[0][4]);
        for(i=1;i<9;i++)for(j=1;j<5;j++)scanf("%s",s[i][j]);
        ans=dfs(1953124);
        printf("%.6lf\n",ans);
    }
    return 0;
}

