
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
    char s[105];
    int dp[105][105];
    int i,j,k,l;
    while(1){
        scanf("%s",s);
        if(!strcmp(s,"end"))break;
        l=strlen(s);
        for(i=0;i<l;i++){
            dp[i][i]=0;
            if((s[i]=='(' && s[i+1]==')') || (s[i]=='[' && s[i+1]==']'))dp[i][i+1] = 2; else dp[i][i+1] = 0;
        }
        for(i=2;i<l;i++){
            for(j=0;i+j<l;j++){
                dp[j][i+j]=0;
                if((s[j]=='(' && s[i+j]==')') || (s[j]=='[' && s[i+j]==']'))dp[j][i+j]=dp[j+1][i+j-1]+2;
                for(k=j;k<i+j;k++)dp[j][i+j]=max(dp[j][i+j],dp[j][k]+dp[k+1][i+j]);
            }
        }
        printf("%d\n",dp[0][l-1]);
    }
    return 0;
}

