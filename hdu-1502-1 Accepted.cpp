
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char dp[65][65][65][85];
void add(char a[],char b[],char back[])
{
    int i,l;
    for(i=0;(i<strlen(a) && i<strlen(b));i++)
    back[i]=a[i]+b[i]-'0';
    for(;i<strlen(a);i++)back[i]=a[i];
    for(;i<strlen(b);i++)back[i]=b[i];
    back[i]=0;l=i;
    for(i=0;i<l;i++)if(back[i]>'9'){
        back[i]-=10;
        back[i+1]++;
    }
    if(back[l]){
        back[l]+='0';
        back[l+1]=0;
    }
}
int main(){
    int n,i,j,k;
    for(i = 0; i<=60; i++)for(j = 0; j<=60; j++)for(k = 0; k<=60; k++)strcpy(dp[i][j][k],"0");
    strcpy(dp[1][0][0],"1");
    for(i=1;i<=60;i++){
        for(j=0;j<=i;j++){
            for(k=0;k<=j;k++){
                if(i-1>=j)add(dp[i-1][j][k],dp[i][j][k],dp[i][j][k]);
                if(j-1>=k)add(dp[i][j-1][k],dp[i][j][k],dp[i][j][k]);
                if(j>=k-1)add(dp[i][j][k],dp[i][j][k-1],dp[i][j][k]);
            }
        }
    }
    while(scanf("%d",&n)!=EOF){
        for(i=strlen(dp[n][n][n])-1;i>-1;i--)printf("%c",dp[n][n][n][i]);
        printf("\n\n");
    }
    return 0;
}

