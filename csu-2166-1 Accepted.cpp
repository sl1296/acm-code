
#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
char s[maxn][maxn];
int n,m;
int check(int i,int j,int ty){
    if(ty==1&&i<n-1&&j>=2&&s[i][j]=='^'&&s[i][j-2]=='^'&&s[i+1][j-1]=='v') return 1;
    if(ty==2&&i<n-1&&j>=2&&s[i][j-1]=='^'&&s[i+1][j-2]=='v'&&s[i+1][j]=='v') return 1;
    if(ty==3&&i<n-2&&j>=1&&s[i][j-1]=='<'&&s[i+1][j]=='>'&&s[i+2][j-1]=='<') return 1;
    if(ty==4&&i<n-2&&j>=1&&s[i][j]=='>'&&s[i+1][j-1]=='<'&&s[i+2][j]=='>') return 1;
    return 0;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",s[i]);
        int ans=0;
        for(int i=0;i<n-1;i++){
            for(int j=2;j<m;j++){
                if(check(i,j,1)){
                    ans++;
                    s[i+1][j-1]=s[i][j-2]=s[i][j]='#';
                }
                if(check(i,j,2)){
                    ans++;
                    s[i][j-1]=s[i+1][j-2]=s[i+1][j]='#';
                }
            }
        }
        for(int i=0;i<n-2;i++){
            for(int j=1;j<m;j++){
                if(check(i,j,3)){
                    ans++;
                    s[i][j-1]=s[i+1][j]=s[i+2][j-1]='#';
                }
                if(check(i,j,4)){
                    ans++;
                    s[i][j]=s[i+1][j-1]=s[i+2][j]='#';
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

