
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int p[500],d[500],v[500],s[500];
int dp[25][2010];
int pre[25][2010];
int cas;
bool check(int x,int y,int val){
    while(pre[x][y]!=-1){
        if(pre[x][y]==val)return false;
        y=y-v[pre[x][y]];
        x--;
    }
    return true;
}
int main(){
    int n,m;
    while(1){
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&p[i],&d[i]);
            v[i]=p[i]-d[i];
            s[i]=p[i]+d[i];
        }
        memset(dp,-1,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        dp[0][1000]=0;
        for(int i=1;i<=m;i++){
            for(int j=500;j<1500;j++){
                if(dp[i-1][j]!=-1){
                    for(int k=1;k<=n;k++){
                        if(check(i-1,j,k)){
                            if(dp[i][j+v[k]]<dp[i-1][j]+s[k]){
                                dp[i][j+v[k]]=dp[i-1][j]+s[k];
                                pre[i][j+v[k]]=k;
                            }
                        }
                    }
                }
            }
        }
        int ans=0;
        for(int j=0;j<490;j++){
            if(dp[m][1000+j]!=-1||dp[m][1000-j]!=-1){
                if(dp[m][1000+j]<dp[m][1000-j]){
                    ans=1000-j;
                }else{
                    ans=1000+j;
                }
                break;
            }
        }
        int out[21];
        int xx=m,yy=ans;
        int dd=0,pp=0;
        for(int i=0;i<m;i++){
            out[i]=pre[xx][yy];
            dd+=d[out[i]];
            pp+=p[out[i]];
            yy=yy-v[pre[xx][yy]];
            xx--;
        }
        sort(out,out+m);
        printf("Jury #%d\n",++cas);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",pp,dd);
        for(int i=0;i<m;i++)printf(" %d",out[i]);
        printf("\n");
    }
    return 0;
}

