
#include<bits/stdc++.h>
using namespace std;
char m[110][110],t[110][110];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int mx=0;
        for(int i=0;i<n;i++)scanf("%s",m[i]);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)m[i][j]-=48;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(m[i][j]){
                    for(int k=0;k<n;k++)t[k][j]=m[k][j];
                }else{
                    for(int k=0;k<n;k++)t[k][j]=!m[k][j];
                }
            }
            for(int j=0;j<n;j++){
                int k;
                for(k=0;k<n;k++)if(t[j][k]==0)break;
                if(k==n)c++;
            }
            mx=max(c,mx);
        }
        printf("%d\n",mx);
    }
    return 0;
}

