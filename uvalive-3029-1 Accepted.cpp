
#include<bits/stdc++.h>
using namespace std;
bool a[1010][1010];
int lef[1010][1010],up[1010][1010],righ[1010][1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char s[5];
                scanf("%s",s);
                a[i][j]=(s[0]=='F')?false:true;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            int lx=-1,rx=n;
            for(int j=0;j<n;j++){
                if(a[i][j]){
                    up[i][j]=lef[i][j]=0;
                    lx=j;
                }else{
                    up[i][j]=i?(up[i-1][j]+1):1;
                    lef[i][j]=i?max(lef[i-1][j],lx+1):lx+1;
                }
            }
            for(int j=n-1;j>-1;j--){
                if(a[i][j]){
                    righ[i][j]=n;
                    rx=j;
                }else{
                    righ[i][j]=i?min(righ[i-1][j],rx-1):rx-1;
                    ans=max(ans,up[i][j]*(righ[i][j]-lef[i][j]+1));
                }
            }
        }
        printf("%d\n",ans*3);
    }
    return 0;
}

